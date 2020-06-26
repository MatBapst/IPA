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
#include <visualization_msgs/Marker.h>
#include <pcl/common/common.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <vector>
#include <pcl/common/centroid.h>

tf::TransformListener* hand_listener;  

// out box
const Eigen::Vector4f min_box =Eigen::Vector4f(-0.2,-0.2,-0.2,1);
const Eigen::Vector4f max_box =Eigen::Vector4f(0.2,0.2,0.2,1);





ros::Publisher pub;
ros::Publisher point_pub;

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
    tf::StampedTransform transform_hand;
    tf::StampedTransform transform_elbow;
    sensor_msgs::PointCloud2 output;
    
    
    try{
      hand_listener->lookupTransform("/world", "/cam3_link/left_hand",  
                               ros::Time(0), transform_hand);

        Eigen::Vector3f t=Eigen::Vector3f(transform_hand.getOrigin().x(),transform_hand.getOrigin().y(),transform_hand.getOrigin().z());
        Eigen::Quaterniond q;
        tf::quaternionTFToEigen(transform_hand.getRotation(), q);
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

        
        //crop the rest of the arm
        hand_listener->lookupTransform("/world", "/cam3_link/left_elbow",  
                               ros::Time(0), transform_elbow);
        Eigen::Vector3f t_elb=Eigen::Vector3f(transform_elbow.getOrigin().x(),transform_elbow.getOrigin().y(),transform_elbow.getOrigin().z());
        Eigen::Quaterniond q_elb;
        tf::quaternionTFToEigen(transform_elbow.getRotation(), q_elb);
        Eigen::Vector3d r_elb=q.toRotationMatrix().eulerAngles(2,1,0);
        Eigen::Vector3f r_f_elb=Eigen::Vector3f(r_elb[0],r_elb[1],r_elb[2]);

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_2 (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_3 (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ> cloud_filtered_pcl;
        pcl::fromPCLPointCloud2(*cloud_filtered,*cloud_filtered_2);


        pcl::StatisticalOutlierRemoval<pcl::PointXYZ> filter;
        filter.setInputCloud(cloud_filtered_2);
        filter.setMeanK(30);
        filter.setStddevMulThresh (1); 
        filter.filter(*cloud_filtered_3);

        
        const pcl::PointCloud<pcl::PointXYZ> cloud_filtered_pcl_const=*cloud_filtered_3;

        const Eigen::Vector4f elbow = Eigen::Vector4f(t_elb[0],t_elb[1],t_elb[2],1);
        Eigen::Vector4f tool_max_point;

        pcl::getMaxDistance(cloud_filtered_pcl_const, elbow, tool_max_point);

       


        if (!isnan(tool_max_point[0])) {
            //search for the nearest points from max point to compute the centroid
          
          
          pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
          kdtree.setInputCloud (cloud_filtered_3);
          pcl::PointXYZ searchPoint;
          searchPoint.x=tool_max_point[0];
          searchPoint.y=tool_max_point[1];
          searchPoint.z=tool_max_point[2];
          std::vector<int> pointIdxRadiusSearch;
          std::vector<float> pointRadiusSquaredDistance;
          float radius = 0.03;
          pcl::PointCloud<pcl::PointXYZ>::Ptr max_cloud (new pcl::PointCloud<pcl::PointXYZ>);
          if ( kdtree.radiusSearch (searchPoint, radius, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0 )
            {
              
              max_cloud->width = pointIdxRadiusSearch.size ();
              max_cloud->height = 1;
              max_cloud->points.resize (max_cloud->width * max_cloud->height);
              for (std::size_t i = 0; i < pointIdxRadiusSearch.size (); ++i) {
                pcl::PointXYZ point;
                max_cloud->points[i].x=cloud_filtered_3->points[ pointIdxRadiusSearch[i] ].x;
                max_cloud->points[i].y=cloud_filtered_3->points[ pointIdxRadiusSearch[i] ].y;
                max_cloud->points[i].z=cloud_filtered_3->points[ pointIdxRadiusSearch[i] ].z;
                
              }
            }
          const pcl::PointCloud<pcl::PointXYZ> max_cloud_const=*max_cloud;
          Eigen::Matrix<double,4,1> centroid;
          pcl::compute3DCentroid(max_cloud_const, centroid);
        
          visualization_msgs::Marker points;
          points.header.frame_id = "/world";
          points.header.stamp  = ros::Time::now();
          points.ns = "point";
          points.action = visualization_msgs::Marker::ADD;
          points.pose.orientation.w = 1.0;
          points.id = 0;
          points.type = visualization_msgs::Marker::POINTS;
          points.scale.x = 0.02;
          points.scale.y = 0.02;
          points.color.r = 1.0f;
          points.color.a = 1.0f;
          geometry_msgs::Point p;
          p.x = centroid(0,0);
          p.y = centroid(1,0);
          p.z = centroid(2,0);

          points.points.push_back(p);
          point_pub.publish(points);
        }

        pcl_conversions::fromPCL(*cloud_filtered, output);

    }
    catch (tf::TransformException ex){
      ROS_INFO_STREAM("no hand in cell");
      output.header.frame_id="world";

    }
    
    
    pub.publish(output);
    
}


int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "handover_tool_in_hand_detector");
  ros::NodeHandle nh;

  tf::TransformListener lstnr(ros::Duration(5));
  hand_listener=&lstnr;  

  // Create a ROS subscriber for the input point cloud

  ros::Subscriber sub = nh.subscribe ("/cameras/depth_pointcloud_fusion", 1, cloud_cb); 
  

  // Create a ROS publisher for the output point cloud
  /*pub1 = nh.advertise<sensor_msgs::PointCloud2> ("/cam1/depth/color/points_computed", 1);
  pub2 = nh.advertise<sensor_msgs::PointCloud2> ("/cam2/depth/color/points_computed", 1);
  pub4 = nh.advertise<sensor_msgs::PointCloud2> ("/cam4/depth/color/points_computed", 1);*/

  pub = nh.advertise<sensor_msgs::PointCloud2> ("/handover/hand_pointcloud", 1);
  point_pub = nh.advertise<visualization_msgs::Marker>("/handover/tool_max_point", 1);
  //listener.lookupTransform("/world", "/camL_link", ros::Time(0), transform);
  // Spin
  ros::spin ();
}
