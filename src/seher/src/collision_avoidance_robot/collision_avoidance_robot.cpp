#include "tf/transform_datatypes.h"
#include <std_msgs/Header.h>
#include <std_msgs/Int64.h>
#include "std_msgs/Float32.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <ur_msgs/SetSpeedSliderFraction.h>
#include <std_msgs/Bool.h>
#include "ur_msgs/SetIO.h"

//threshold distance between robot and obstacle to stop the robot
float dist_threshold_low=0.15; //20 cm
float dist_threshold_up=0.3; //40 cm
bool near_obstacle=false;
bool status=false; //true if robot moving, false if robot stopped
float max_robot_speed = 0.5; //corresponds to % of max robot speed like on the Teach Pendant
float distance; //minimal distance between TCP and obstacle
float speed_distance=0.5; // max distance for adjusting the robot speed
float adjusted_speed=max_robot_speed;

float distance_a = (max_robot_speed-0.1)/(speed_distance-dist_threshold_low);
float distance_b = max_robot_speed-distance_a*speed_distance;
bool handover_flag=false;
bool grasp_flag=false;
const int IO_SERVICE_FUN_LEVEL_ = 1;

void distanceCallback (const std_msgs::Float32::ConstPtr& dst){
    distance=dst->data;

    if (distance<=dist_threshold_low){
        near_obstacle=true;
    }
    if (distance>=dist_threshold_up) {
        near_obstacle=false;
    }
}

void handoverCallback (const std_msgs::Bool::ConstPtr& flag){
  if (flag->data){
    handover_flag=true;
    
  }
  else {
    handover_flag=false;
  }
  
}

void graspCallback (const std_msgs::Bool::ConstPtr& flag) {
  if (flag->data){
    grasp_flag=true;
  } else {
    grasp_flag=false;
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

void setSpeed(float wanted_speed){
    ur_msgs::SetSpeedSliderFraction speed;
    
    speed.request.speed_slider_fraction = wanted_speed;
    ros::service::call("/ur_hardware_interface/set_speed_slider",speed);

}

bool gripperOpen(ros::NodeHandle nh)
{
  ur_msgs::SetIO io_msg;
  io_msg.request.fun = static_cast<int8_t>(IO_SERVICE_FUN_LEVEL_);
  io_msg.request.pin = static_cast<int8_t>(1);  //Pin 1 is open
  io_msg.request.state = 1;
  ros::ServiceClient client = nh.serviceClient<ur_msgs::SetIO>("/ur_hardware_interface/set_io");

  if(client.call(io_msg))
  {
    ROS_INFO_STREAM("Open gripper initialise : " << ((io_msg.response.success==0)?"Failed":"Succeeded") );
    sleepSafeFor(0.5);
    io_msg.request.state = 0;
    if(client.call(io_msg))
    {
      ROS_INFO_STREAM("Open gripper conclude : " << ((io_msg.response.success==0)?"Failed":"Succeeded") );
      return true;
    }
    else
    {
      ROS_INFO_STREAM("Open gripper conclude : Failed");
      return false;
    }
  }
  else
  {
    ROS_INFO_STREAM("Open gripper initialise : Failed");
    return false;
  }
}

bool gripperClose(ros::NodeHandle nh)
{
  ur_msgs::SetIO io_msg;
  io_msg.request.fun = static_cast<int8_t>(IO_SERVICE_FUN_LEVEL_);
  io_msg.request.pin = static_cast<int8_t>(0);    //Pin 0 is close
  io_msg.request.state = 1;
  ros::ServiceClient client = nh.serviceClient<ur_msgs::SetIO>("/ur_hardware_interface/set_io");

  if(client.call(io_msg))
  {
    ROS_INFO_STREAM("Close gripper initialise :  " << ((io_msg.response.success==0)?"Failed":"Succeeded") );
    sleepSafeFor(0.5);
    io_msg.request.state = 0;
    if(client.call(io_msg))
    {
      ROS_INFO_STREAM("Close gripper conclude :  " << ((io_msg.response.success==0)?"Failed":"Succeeded") );
      return true;
    }
    else
    {
      ROS_INFO_STREAM("Close gripper conclude : Failed");
      return false;
    }
  }
  else
  {
    ROS_INFO_STREAM("Close gripper initialise : Failed");
    return false;
  }
}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "collision_avoidance_robot");
  ros::NodeHandle nh;
  
  
  ros::AsyncSpinner spinner(1);
  spinner.start();


 ros::Subscriber distance_sub = nh.subscribe("/distance_calculation/minimal_distance",1, distanceCallback);
 ros::Subscriber handover_sub=nh.subscribe("/handover/approach_flag",1, handoverCallback);
 ros::Subscriber grasp_sub=nh.subscribe("/handover/grasp_flag",1, graspCallback);
 
  while(ros::ok())
  {
    if (handover_flag){
      setSpeed(0.1);
      if (!status){
        startRobot();
      }
    } else {
      updateSpeed();
    }
    

    if (near_obstacle && status && !handover_flag){
        stopRobot();
        
    }
    if (!near_obstacle && !status && !handover_flag){
        startRobot();
    }

    if (handover_flag && grasp_flag){
      stopRobot();
      gripperClose(nh);
    }

    

    
    ros::spinOnce();
    
    
  }
return 0;
}