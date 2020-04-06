#include <ros/ros.h>
#include <tf/transform_listener.h>

#include <visualization_msgs/Marker.h>
#include <cmath>



geometry_msgs::Point P;

void distanceCallback (const visualization_msgs::Marker::ConstPtr& point){
    
    P = point->points[0];
    
    

}


int main(int argc, char** argv){
  ros::init(argc, argv, "distance_calculation");

  ros::NodeHandle node;

  
  double distance;
  double x,y,z;
  tf::TransformListener robot_listener;

  ros::Subscriber robot_sub = node.subscribe("/visualization_marker",1, distanceCallback);


   
  ros::Rate rate(30.0);
  while (node.ok()){
    tf::StampedTransform transform;
    try{
      robot_listener.lookupTransform("/world", "/tool0",  
                               ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
    x=transform.getOrigin().x();
    y=transform.getOrigin().y();
    z=transform.getOrigin().z();
    distance= sqrt(pow(P.x-x,2)+pow(P.y-y,2)+pow(P.z-z,2));
    ROS_INFO_STREAM("distance between TCP and point : " << distance);
    ros::spinOnce();
    rate.sleep();
    
  }

  
  return 0;
};
