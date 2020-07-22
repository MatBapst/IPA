#include <ros/ros.h>
#include <tf/transform_listener.h>

#include <visualization_msgs/Marker.h>
#include <cmath>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "std_msgs/Float32.h"
#include <pcl/common/centroid.h>
#include <tf/transform_broadcaster.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <fstream>

float min_distance;

tf::StampedTransform transform_TCP;

//using namespace std;
//ofstream outfile;
//int i =0;

float distanceComputing (geometry_msgs::Point32 point, tf::StampedTransform TCP){
    float distance,x,y,z;
    x=TCP.getOrigin().x();
    y=TCP.getOrigin().y();
    z=TCP.getOrigin().z();
    distance= sqrt(pow(point.x-x,2)+pow(point.y-y,2)+pow(point.z-z,2));
    return distance;
}


void distanceCallback (const sensor_msgs::PointCloud2ConstPtr& input){

    //outfile << i << " : " << ros::Time::now() << endl;
    //i++;
    sensor_msgs::PointCloud pointcloud;
    sensor_msgs::convertPointCloud2ToPointCloud(*input, pointcloud);
    min_distance=100;
    float distance;
    for (int i =0; i<pointcloud.points.size();i++){
        distance=distanceComputing(pointcloud.points[i], transform_TCP);
        if (distance<min_distance){
            min_distance=distance;
        }

    }
    
    // pcl::PCLPointCloud2::Ptr cloud_pcl (new pcl::PCLPointCloud2 ());

    // // Pointcloud cropping : crop the area of the TCP
    // pcl_conversions::toPCL(*input, *cloud_pcl);
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz (new pcl::PointCloud<pcl::PointXYZ>);
    // pcl::fromPCLPointCloud2(*cloud_pcl,*cloud_xyz);

    // const pcl::PointCloud<pcl::PointXYZ> cloud_const=*cloud_xyz;
    // Eigen::Matrix<double,4,1> occupancyMap_centroid;
    // pcl::compute3DCentroid(cloud_const, occupancyMap_centroid);
    // static tf::TransformBroadcaster br;
    // tf::Transform transform;
    // //tf::Quaternion tf_q;
    // //tf::quaternionEigenToTF(q,tf_q);
    // transform.setOrigin(tf::Vector3(occupancyMap_centroid(0,0), occupancyMap_centroid(1,0), occupancyMap_centroid(2,0)));
    // transform.setRotation(tf::createQuaternionFromRPY(0, 0, 0));
    // br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/world", "/occupancyMap_centroid"));


}




int main(int argc, char** argv){
  ros::init(argc, argv, "distance_calculation");

  ros::NodeHandle node;

  
  
  tf::TransformListener robot_listener;

  ros::Subscriber robot_sub = node.subscribe("/cameras/depth_pointcloud_fusion_final",1, distanceCallback);
  ros::Publisher distance_pub=node.advertise<std_msgs::Float32>("/distance_calculation/minimal_distance",1);

   
  ros::Rate rate(30.0);

  
  //outfile.open("loop_time_final_pointcloud_callback.dat");
  
  while (node.ok()){
    
    try{
      robot_listener.lookupTransform("/world", "/egp50_body_link",  
                               ros::Time(0), transform_TCP);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
    
    ros::spinOnce();

    ROS_INFO_STREAM("minimal distance between TCP and pointcloud : " << min_distance);
    std_msgs::Float32 msg;
    msg.data=min_distance;
    distance_pub.publish(msg);
    rate.sleep();
    
  }

  
  return 0;
};
