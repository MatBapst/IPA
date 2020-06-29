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
#include <pcl/kdtree/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>

tf::TransformListener* TCP_listener;  

const Eigen::Vector4f min_box =Eigen::Vector4f(-0.15,-0.05,-0.05,1);
const Eigen::Vector4f max_box =Eigen::Vector4f(0.05,0.05,0.05,1);

ros::Publisher pub;

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
    tf::StampedTransform transform_TCP;
    try{
      TCP_listener->lookupTransform("/world", "/egp50_pincer_link",  
                               ros::Time(0), transform_TCP);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
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
    
    //cropFilter.setTransform(trans2);
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

  std::vector<pcl::PointIndices> cluster_indices;
  pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
  ec.setClusterTolerance (0.025); // 2cm
  ec.setMinClusterSize (15);
  ec.setMaxClusterSize (2000);
  ec.setSearchMethod (tree);
  ec.setInputCloud (cloud_filtered_2);
  ec.extract (cluster_indices);

  std::vector<sensor_msgs::PointCloud2::Ptr> pc2_clusters;
  std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr > clusters;

  int j = 0;
   
  sensor_msgs::PointCloud2 output; 
  ROS_INFO_STREAM("Number of clusters : " << cluster_indices.size());
  if (!cluster_indices.empty()) {
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
  }

    pub.publish(output);

    /*sensor_msgs::PointCloud2 output;
    pcl_conversions::fromPCL(*cloud_filtered, output);

    pub.publish(output);*/
    
}


int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "handover_grasping_detector");
  ros::NodeHandle nh;

  tf::TransformListener lstnr(ros::Duration(5));
  TCP_listener=&lstnr;  

  // Create a ROS subscriber for the input point cloud

  ros::Subscriber sub = nh.subscribe ("/cameras/depth_pointcloud_fusion", 1, cloud_cb); 
  

  // Create a ROS publisher for the output point cloud
  /*pub1 = nh.advertise<sensor_msgs::PointCloud2> ("/cam1/depth/color/points_computed", 1);
  pub2 = nh.advertise<sensor_msgs::PointCloud2> ("/cam2/depth/color/points_computed", 1);
  pub4 = nh.advertise<sensor_msgs::PointCloud2> ("/cam4/depth/color/points_computed", 1);*/

  pub = nh.advertise<sensor_msgs::PointCloud2> ("/handover/TCP_pointcloud", 1);
  //listener.lookupTransform("/world", "/camL_link", ros::Time(0), transform);
  // Spin
  ros::spin ();
}
