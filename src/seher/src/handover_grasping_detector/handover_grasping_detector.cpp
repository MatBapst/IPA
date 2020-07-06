#include <pcl/filters/crop_box.h>
#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>

#include <Eigen/Dense>

//#include <tf/quaternion.h>
#include "tf/transform_datatypes.h"
#include <Eigen/Geometry>
#include "Eigen/Core"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <iostream>
#include "tf/transform_listener.h"
#include "tf_conversions/tf_eigen.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_ros/transforms.h>

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/segmentation/extract_clusters.h>
#include <std_msgs/Bool.h>

tf::TransformListener* TCP_listener;  

const Eigen::Vector4f min_box =Eigen::Vector4f(-0.05,-0.03,-0.03,1); //0.15 0.05 0.2
const Eigen::Vector4f max_box =Eigen::Vector4f(0.01,0.03,0.03,1);

const int cluster_points_threshold=250;
const float max_distance_threshold=0.05;
const ros::Duration grasp_timer_threshold=ros::Duration(2.0);

ros::Publisher pub;
ros::Publisher pub_grasp;

bool approach_flag=false;
bool handover_dir_flag=true; // if true handover from robot to human, else handover from human to robot


float distanceComputing (tf::StampedTransform TCP1, tf::StampedTransform TCP2){
    float distance,x,y,z,x2,y2,z2;
    x=TCP1.getOrigin().x();
    y=TCP1.getOrigin().y();
    z=TCP1.getOrigin().z();
    x2=TCP2.getOrigin().x();
    y2=TCP2.getOrigin().y();
    z2=TCP2.getOrigin().z();
    distance= sqrt(pow(x2-x,2)+pow(y2-y,2)+pow(z2-z,2));
    return distance;
}

float distanceComputing_points (pcl::PointXYZ point, tf::StampedTransform TCP){
    float distance,x,y,z;
    x=TCP.getOrigin().x();
    y=TCP.getOrigin().y();
    z=TCP.getOrigin().z();
    distance= sqrt(pow(point.x-x,2)+pow(point.y-y,2)+pow(point.z-z,2));
    return distance;
}

void handoverCallback (const std_msgs::Bool::ConstPtr& flag){
  if (flag->data){
    handover_dir_flag=true;
    
  }
  else {
    handover_dir_flag=false;
  }
  
}

void handoverDirCallback (const std_msgs::Bool::ConstPtr& flag){
  if (flag->data){
    approach_flag=true;
    
  }
  else {
    approach_flag=false;
  }
  
}

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
  if (approach_flag) {
    if (handover_dir_flag){

    
      //flags to determine if it is grasped or not
      bool cluster_flag=false;
      bool hand_distance_flag=false;
      bool max_distance_flag=false;
      bool on_tool_flag=false;

      tf::StampedTransform transform_TCP;
      tf::StampedTransform transform_hand;
      try{
        TCP_listener->lookupTransform("/world", "/cam3_link/left_hand",  
                                ros::Time(0), transform_hand);
      }
      catch (tf::TransformException ex){
        //ROS_WARN_STREAM("no hand detected");
        
      }
      try{
        TCP_listener->lookupTransform("/world", "/egp_50_tip",  
                                ros::Time(0), transform_TCP);
      }
      catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
        ros::Duration(1.0).sleep();
      }
      float TCP_hand_distance=distanceComputing(transform_hand, transform_TCP);
      //ROS_INFO_STREAM("Distance between hand and TCP: " << TCP_hand_distance);
      if (TCP_hand_distance > 0.1 && TCP_hand_distance < 0.25){
          hand_distance_flag=true;
      }
      Eigen::Vector3f t=Eigen::Vector3f(transform_TCP.getOrigin().x(),transform_TCP.getOrigin().y(),transform_TCP.getOrigin().z());
      Eigen::Quaterniond q;
      tf::quaternionTFToEigen(transform_TCP.getRotation(), q);
      Eigen::Vector3d r=q.toRotationMatrix().eulerAngles(2,1,0);
      Eigen::Vector3f r_f=Eigen::Vector3f(r[0],r[1],r[2]);
      pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
      pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
      pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

      // Pointcloud cropping : crop the area of the TCP
      pcl_conversions::toPCL(*input, *cloud);

      pcl::CropBox<pcl::PCLPointCloud2> cropFilter;
      
      
      cropFilter.setMin(min_box);
      cropFilter.setMax(max_box);
      cropFilter.setTranslation(t);
      cropFilter.setRotation(r_f);
      cropFilter.setInputCloud(cloudPtr);
      cropFilter.filter(*cloud_filtered);
      
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_2 (new pcl::PointCloud<pcl::PointXYZ>);
      pcl::fromPCLPointCloud2(*cloud_filtered,*cloud_filtered_2);

      pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
      tree->setInputCloud (cloud_filtered_2);
    float max=0;
    int nb_points=0;
    for (int pit = 0; pit < cloud_filtered_2->size(); ++pit){
      float dist =distanceComputing_points(cloud_filtered_2->at(pit), transform_TCP);
      if (dist > max ){
        max=dist;
      }
    }

    if (max < max_distance_threshold){
      max_distance_flag=true;
    }

    //ROS_INFO_STREAM("max distance in the cropped cloud: " << max);
    std::vector<pcl::PointIndices> cluster_indices;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
    ec.setClusterTolerance (0.004); // 4 mm
    ec.setMinClusterSize (30);
    ec.setMaxClusterSize (2000);
    ec.setSearchMethod (tree);
    ec.setInputCloud (cloud_filtered_2);
    ec.extract (cluster_indices);

    

    //std::vector<sensor_msgs::PointCloud2::Ptr> pc2_clusters;
    //std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr > clusters;

    int j = 0;
    
    sensor_msgs::PointCloud2 output; 
    //ROS_INFO_STREAM("Number of clusters : " << cluster_indices.size());
    //ROS_INFO_STREAM("nb of points in cluster: " << cluster_indices[0].indices.size());
    if (cluster_indices.size()==1 && cluster_indices[0].indices.size()>=cluster_points_threshold ){
      
      cluster_flag=true;
    }
    /*if (!cluster_indices.empty()) {
    for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it)
    {
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
      for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); ++pit)
        cloud_cluster->points.push_back (cloud_filtered_2->points[*pit]); //*
      cloud_cluster->width = cloud_cluster->points.size ();
      cloud_cluster->height = 1;
      cloud_cluster->is_dense = true;

      //std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size () << " data points." << std::endl;

      clusters.push_back(cloud_cluster);
      sensor_msgs::PointCloud2::Ptr tempROSMsg(new sensor_msgs::PointCloud2);
      pcl::toROSMsg(*cloud_cluster, *tempROSMsg);
      tempROSMsg->header.frame_id="world";
      pc2_clusters.push_back(tempROSMsg);
      output=*(pc2_clusters.at(0));
    }
    
    }
    else{
        output.header.frame_id="world";
        output.data.clear();
        output.is_dense=true;
    }*/
    ros::Time grasp_timer;
    std_msgs::Bool flag; 
    flag.data=false;
    if (cluster_flag && max_distance_flag && hand_distance_flag){
      on_tool_flag=true;
      
    }
    if (!on_tool_flag){
      grasp_timer=ros::Time::now();
    }
    if (ros::Time::now()-grasp_timer>grasp_timer_threshold) {
      flag.data=true;
    }
    pub_grasp.publish(flag);
    //ROS_INFO_STREAM("General Flag: " << on_tool_flag);
      //pub.publish(output);

      //sensor_msgs::PointCloud2 output2;
      //pcl_conversions::fromPCL(*cloud_filtered, output);

      //pub.publish(output);
    } else {
      // determine if hand is on tool in order to open gripper
    }
  }  
    
}




int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "handover_grasping_detector");
  ros::NodeHandle nh;

  tf::TransformListener lstnr(ros::Duration(5));
  TCP_listener=&lstnr;  

  // Create a ROS subscriber for the input point cloud

  ros::Subscriber sub = nh.subscribe ("/cameras/raw_depth_pointcloud_fusion", 1, cloud_cb); 
  
  ros::Subscriber handover_sub=nh.subscribe("/handover/approach_flag",1, handoverCallback);
  ros::Subscriber handover_direction_sub=nh.subscribe("/handover/direction",1, handoverDirCallback);
  
  // Create a ROS publisher for the output point cloud
  /*pub1 = nh.advertise<sensor_msgs::PointCloud2> ("/cam1/depth/color/points_computed", 1);
  pub2 = nh.advertise<sensor_msgs::PointCloud2> ("/cam2/depth/color/points_computed", 1);
  pub4 = nh.advertise<sensor_msgs::PointCloud2> ("/cam4/depth/color/points_computed", 1);*/

  //pub = nh.advertise<sensor_msgs::PointCloud2> ("/handover/TCP_pointcloud", 1);
  pub_grasp = nh.advertise<std_msgs::Bool> ("/handover/grasp_flag", 1);
  //listener.lookupTransform("/world", "/camL_link", ros::Time(0), transform);
  // Spin
  ros::spin ();
}
