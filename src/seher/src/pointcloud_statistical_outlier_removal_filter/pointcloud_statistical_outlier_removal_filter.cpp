#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>

ros::Publisher pub;


void filter_cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
    sensor_msgs::PointCloud2 output;
   
    
    pcl::PCLPointCloud2* input_pcl2 (new pcl::PCLPointCloud2 ());
    pcl_conversions::toPCL(*input, *input_pcl2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr input_xyz (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr output1 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr output_xyz (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(*input_pcl2,*input_xyz);
    if (!input_xyz->empty()){
      
      pcl::RadiusOutlierRemoval<pcl::PointXYZ> ror_filter;
      ror_filter.setInputCloud(input_xyz);
      ror_filter.setRadiusSearch(0.15);
      ror_filter.setMinNeighborsInRadius(120);
      ror_filter.filter(*output1);
      if (!output1->empty()){
        pcl::StatisticalOutlierRemoval<pcl::PointXYZ> filter;
        filter.setInputCloud(output1);
        filter.setMeanK(50);
        filter.setStddevMulThresh (0.5); 
        filter.filter(*output_xyz);
      } else {
        *output_xyz=*output1;
      }
      
      pcl::PCLPointCloud2::Ptr output_pcl2 (new pcl::PCLPointCloud2 ());
      pcl::toPCLPointCloud2(*output_xyz, *output_pcl2);
      pcl_conversions::fromPCL(*output_pcl2, output);
    } else {
      output=*input;
    }
    pub.publish(output);


}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "pointcloud_statistical_outlier_filter");
  ros::NodeHandle nh;


  // Create a ROS subscriber for the input point cloud

  ros::Subscriber sub = nh.subscribe ("/cameras/depth_pointcloud_fusion_filtered", 1, filter_cloud_cb); //from camL
  

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("/cameras/depth_pointcloud_fusion_final", 1);
  
  //listener.lookupTransform("/world", "/camL_link", ros::Time(0), transform);
  // Spin
  ros::spin ();
}