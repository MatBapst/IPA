#include <pcl/filters/crop_box.h>
#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>

#include <Eigen/Dense>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

ros::Publisher pub1;
ros::Publisher pub2;

ros::Subscriber sub1;
ros::Subscriber sub2;




//workcell 
const Eigen::Vector4f min_workcell =Eigen::Vector4f(0,0,0,1);
const Eigen::Vector4f max_workcell =Eigen::Vector4f(1.0,1.0,1.50,1);

//const Eigen::Vector4f min_workcell =Eigen::Vector4f(0.076f,0.793f,1.625f,1); // ok ?
//const Eigen::Vector4f max_workcell =Eigen::Vector4f(0.294f--0.77f,0.29f,1);


const Eigen::Vector3f t2=Eigen::Vector3f(-0.5f,-0.5f,0.0f);
const Eigen::Vector3f r2=Eigen::Vector3f(0.0f,0.0f,0.0f);



void cloud_cb1 (const sensor_msgs::PointCloud2ConstPtr& input)
{
  // Create a container for the data.
  sensor_msgs::PointCloud2 output;
  
 pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
 pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
 pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

 pcl::PCLPointCloud2::Ptr voxel_cloud (new pcl::PCLPointCloud2 ());

 // Do data processing here...
 pcl_conversions::toPCL(*input, *cloud);

  

  
  pcl::CropBox<pcl::PCLPointCloud2> cropFilter;
  
  //cropFilter.setTransform(trans2);
  cropFilter.setMin(min_workcell);
  cropFilter.setMax(max_workcell);
  cropFilter.setTranslation(t2);
  //cropFilter.setRotation(r2);
  cropFilter.setInputCloud(cloudPtr);
  cropFilter.filter(*cloud_filtered);
  

  

  pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  sor.setInputCloud (cloud_filtered);
  sor.setLeafSize (0.01f, 0.01f, 0.01f);
  sor.filter (*voxel_cloud);

pcl_conversions::fromPCL(*voxel_cloud, output);

  // Publish the data.
  pub1.publish (output);
}


void cloud_cb2 (const sensor_msgs::PointCloud2ConstPtr& input)
{
  // Create a container for the data.
  sensor_msgs::PointCloud2 output;
  
 pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
 pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
 pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

 pcl::PCLPointCloud2::Ptr voxel_cloud (new pcl::PCLPointCloud2 ());

 // Do data processing here...
 pcl_conversions::toPCL(*input, *cloud);

  

  
  pcl::CropBox<pcl::PCLPointCloud2> cropFilter;
  
  //cropFilter.setTransform(trans2);
  cropFilter.setMin(min_workcell);
  cropFilter.setMax(max_workcell);
  cropFilter.setTranslation(t2);
  //cropFilter.setRotation(r2);
  cropFilter.setInputCloud(cloudPtr);
  cropFilter.filter(*cloud_filtered);
  

  

  pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  sor.setInputCloud (cloud_filtered);
  sor.setLeafSize (0.01f, 0.01f, 0.01f);
  sor.filter (*voxel_cloud);

pcl_conversions::fromPCL(*voxel_cloud, output);

  // Publish the data.
  pub2.publish (output);
}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "pointcloud_compute");
  ros::NodeHandle nh;

  //std::cout << "min" << min_workcell2;
//std::cout << "max" << max_workcell2;

  // Create a ROS subscriber for the input point cloud
  sub1 = nh.subscribe ("/camL/depth/color/points", 1, cloud_cb1);
  sub2 = nh.subscribe ("/camR/depth/color/points", 1, cloud_cb2);
  // Create a ROS publisher for the output point cloud
  pub1 = nh.advertise<sensor_msgs::PointCloud2> ("/camL/depth/color/points_computed", 1);
  pub2 = nh.advertise<sensor_msgs::PointCloud2> ("/camR/depth/color/points_computed", 1);
  // Spin
  ros::spin ();
}

