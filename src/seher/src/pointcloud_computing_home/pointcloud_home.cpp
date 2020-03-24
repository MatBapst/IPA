#include <pcl/filters/crop_box.h>
#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>

#include <Eigen/Dense>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <iostream>

ros::Publisher pub1;
ros::Publisher pub2;
ros::Publisher pub3;
ros::Publisher pub4;

ros::Subscriber sub1;
ros::Subscriber sub2;
ros::Subscriber sub3;
ros::Subscriber sub4;

//for cam2
const float x2 = -0.418;
const float y2 = 1.16;
const float z2= 1.097;
const float yaw2=-1.0472;
const float pitch2=0.7854;
const float roll2=-1.5708;

//workcell 
const Eigen::Vector4f min_workcell =Eigen::Vector4f(0,0,0,1);
const Eigen::Vector4f max_workcell =Eigen::Vector4f(1.097,0.96,1.47,1);

//const Eigen::Vector4f min_workcell =Eigen::Vector4f(0.076f,0.793f,1.625f,1); // ok ?
//const Eigen::Vector4f max_workcell =Eigen::Vector4f(0.294f--0.77f,0.29f,1);


const Eigen::Vector3f t2=Eigen::Vector3f(-0.475f,-0.1f,0.8f);
const Eigen::Vector3f r2=Eigen::Vector3f(0.24f,0.46f,0.10f);

/*Eigen::Vector4f affine_transform(Eigen::Vector4f point, Eigen::Vector3f trans){
  Eigen::Matrix3f R2(3,3);
    R2 << 0.353f, -0.612f, -0.707f,
      -0.353f, 0.612f, -0.707f,
      0.866f, 0.5f, 0.0f;
    Eigen::Matrix4f m;
    Eigen::Vector4f p;
    m.setIdentity();
    m.block<3,3>(0,0)=R2;
    m.block<3,1>(0,3)=trans;
    p=m*point;
    std::cout << p;
    return p;
}

Eigen::Vector4f transform(Eigen::Vector4f point, float x,float y,float z){
  Eigen::Vector4f p;
  p=point+Eigen::Vector4f(x,y,z,1);
  std::cout << "p" << p;
  return p;
}

//Eigen::Affine3f trans2 =create_affine_transform(x2,y2,z2,yaw2,pitch2,roll2);
Eigen::Vector4f min_workcell2=affine_transform(min_workcell,t2);
Eigen::Vector4f max_workcell2=affine_transform(max_workcell,t2);*/

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input2)
{
  // Create a container for the data.
  sensor_msgs::PointCloud2 output2;
  
 pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
 pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
 pcl::PCLPointCloud2 cloud_filtered;

 // Do data processing here...
 pcl_conversions::toPCL(*input2, *cloud);

  

  
  pcl::CropBox<pcl::PCLPointCloud2> cropFilter;
  
  //cropFilter.setTransform(trans2);
  cropFilter.setMin(min_workcell);
  cropFilter.setMax(max_workcell);
  cropFilter.setTranslation(t2);
  cropFilter.setRotation(r2);
  cropFilter.setInputCloud(cloudPtr);
  cropFilter.filter(cloud_filtered);
  

  pcl_conversions::fromPCL(cloud_filtered, output2);
  // Publish the data.
  pub2.publish (output2);
}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;

  //std::cout << "min" << min_workcell2;
//std::cout << "max" << max_workcell2;

  // Create a ROS subscriber for the input point cloud
  sub2 = nh.subscribe ("/cam2/depth/color/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub2 = nh.advertise<sensor_msgs::PointCloud2> ("/cam2/depth/color/points_filtered", 1);

  // Spin
  ros::spin ();
}

