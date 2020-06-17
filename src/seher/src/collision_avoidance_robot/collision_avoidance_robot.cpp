#include "tf/transform_datatypes.h"
#include <std_msgs/Header.h>
#include <std_msgs/Int64.h>
#include "std_msgs/Float32.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <ur_msgs/SetSpeedSliderFraction.h>


//threshold distance between robot and obstacle to stop the robot
float dist_threshold_low=0.15; //20 cm
float dist_threshold_up=0.3; //40 cm
bool near_obstacle=false;
bool status=false; //true if robot moving, false if robot stopped
float max_robot_speed = 0.3; //corresponds to % of max robot speed like on the Teach Pendant
float distance; //minimal distance between TCP and obstacle
float speed_distance=0.5; // max distance for adjusting the robot speed
float adjusted_speed=max_robot_speed;

float distance_a = (max_robot_speed-0.1)/(speed_distance-dist_threshold_low);
float distance_b = max_robot_speed-distance_a*speed_distance;

void distanceCallback (const std_msgs::Float32::ConstPtr& dst){
    distance=dst->data;

    if (distance<=dist_threshold_low){
        near_obstacle=true;
    }
    if (distance>=dist_threshold_up) {
        near_obstacle=false;
    }
}

void startRobot(){
  ROS_WARN_STREAM("Robot Starting");
  std_srvs::Trigger trig;
  ros::service::call("/ur_hardware_interface/dashboard/play",trig); //to start the robot
  status=true;
}

void sleepSafeFor(double duration)
{
  ros::Time start = ros::Time::now();
  while(ros::Time::now() - start <= ros::Duration(duration))
  {
    ros::spinOnce();
  }

}

void stopRobot(){
    ROS_WARN_STREAM("Robot Stopping");
    std_srvs::Trigger trig;
    ros::service::call("/ur_hardware_interface/dashboard/pause",trig); //to stop the robot
    status=false;
    sleepSafeFor(1.0);
}

void updateSpeed(){
    ur_msgs::SetSpeedSliderFraction speed;
    adjusted_speed=(adjusted_speed+distance_a*distance+distance_b)/2.0;
    speed.request.speed_slider_fraction = std::min(max_robot_speed, adjusted_speed);
    ros::service::call("/ur_hardware_interface/set_speed_slider",speed);

}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "collision_avoidance_robot");
  ros::NodeHandle nh;
  
  
  ros::AsyncSpinner spinner(1);
  spinner.start();


 ros::Subscriber distance_sub = nh.subscribe("/distance_calculation/minimal_distance",1, distanceCallback);
 
  while(ros::ok())
  {
    updateSpeed();

    if (near_obstacle && status){
        stopRobot();
        
    }
    if (!near_obstacle && !status){
        startRobot();
    }

    
    ros::spinOnce();
    
    
  }
return 0;
}