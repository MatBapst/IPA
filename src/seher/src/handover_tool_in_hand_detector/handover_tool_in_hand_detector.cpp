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


tf::TransformListener* hand_listener;  

const Eigen::Vector4f min_box =Eigen::Vector4f(-0.15,-0.15,-0.15,1);
const Eigen::Vector4f max_box =Eigen::Vector4f(0.15,0.15,0.15,1);

ros::Publisher pub;

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
    tf::StampedTransform transform_hand;
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
        
        
        pcl_conversions::fromPCL(*cloud_filtered, output);
    }
    catch (tf::TransformException ex){
      ROS_INFO_STREAM("no hand in cell");

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
  //listener.lookupTransform("/world", "/camL_link", ros::Time(0), transform);
  // Spin
  ros::spin ();
}
