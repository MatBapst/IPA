#include "seher/move_robot/move_robot.h"
#include "tf/transform_datatypes.h"
#include <angles/angles.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int64.h>
#include "std_msgs/Float32.h"
#include "actionlib_msgs/GoalID.h"
#include "std_msgs/Float64.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <ur_msgs/SetSpeedSliderFraction.h>
#include <std_msgs/Bool.h>



ros::Publisher handover_pub;

//constructor
MoveRobot::MoveRobot()
{


hand_position_current.z=-1.0;
hand_position_old.z=-1.0;
hand_timer=ros::Time::now();
hand_timer_threshold=ros::Duration(3.0);
hand_tolerance=0.03; //3 cm
_status = nominal_task;

}

//Destructor
MoveRobot::~MoveRobot() {}

void MoveRobot::initialiseMoveit(ros::NodeHandle nh)
{
  namespace rvt = rviz_visual_tools;
  move_group = new moveit::planning_interface::MoveGroupInterface(GROUP_MANIP);
  joint_model_group = move_group->getCurrentState()->getJointModelGroup(GROUP_MANIP);
  move_group->setPlannerId("RRTConnectkConfigDefault");

  visual_tools = new moveit_visual_tools::MoveItVisualTools("base_link");
  visual_tools->deleteAllMarkers();
  visual_tools->loadRemoteControl();
  text_pose.translation().z() = 1.75;
  visual_tools->publishText(text_pose, "move Robot for seher", rvt::WHITE, rvt::XLARGE);
  visual_tools->trigger();
  //planning_scene_diff_publisher = nh.advertise<moveit_msgs::PlanningScene>("planning_scene", 1);

}

bool MoveRobot::comparePoses(geometry_msgs::Pose pose1, geometry_msgs::Pose pose2, double delta_posistion, double delta_orientation)
{

  if (  abs(pose1.position.x-pose2.position.x ) <= delta_posistion
        && abs(pose1.position.y-pose2.position.y ) <= delta_posistion
        && abs(pose1.position.z-pose2.position.z ) <= delta_posistion
        && abs(pose1.orientation.x - pose2.orientation.x) <= delta_orientation
        && abs(pose1.orientation.y - pose2.orientation.y) <= delta_orientation
        && abs(pose1.orientation.z - pose2.orientation.z) <= delta_orientation
        && abs(pose1.orientation.w - pose2.orientation.w) <= delta_orientation
     )
  {
    return true;
  }
  else
  {
    return false;
  }
}

void MoveRobot::sleepSafeFor(double duration)
{
  ros::Time start = ros::Time::now();
  while(ros::Time::now() - start <= ros::Duration(duration))
  {
    ros::spinOnce();
  }

}


void MoveRobot::executeCartesianTrajtoPose(geometry_msgs::Pose target)
{
  int trial=0;
  while(trial<10)
  {
    if(moveGroupExecutePlan(getCartesianPathPlanToPose(target)))
    {
      return;
    }
    //ROS_ERROR_STREAM("Execution to " << label << " trial " << trial++ << " failed. Reattempting");
    //failure_counter_++;
    trial++;
  }
  ROS_ERROR_STREAM("Maxx execution attempts reached, error");
  if (_status==nominal_task){
    sleepSafeFor(1.0);
  }
  
}

bool MoveRobot::moveGroupExecutePlan(moveit::planning_interface::MoveGroupInterface::Plan my_plan)
{

  
  move_group->setStartStateToCurrentState();
  
  return move_group->execute(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS;;
}

bool MoveRobot::moveToTarget(geometry_msgs::Pose target)
{
  namespace rvt = rviz_visual_tools;
  bool plan_success = false;
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  

  move_group->setStartStateToCurrentState();
  move_group->setPoseTarget(target);

  plan_success = (move_group->plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
  
  visual_tools->publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
  visual_tools->publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
  visual_tools->trigger();
  
  if (plan_success){
    if ( move_group->move()==moveit::planning_interface::MoveItErrorCode::SUCCESS){
        
        ROS_INFO_STREAM("MOVING");
        
        return true;
    }
    ROS_INFO_STREAM("NOT MOVING");
    
  } else {
    ROS_WARN_STREAM("Failed planning");
  }
  return false;
}


moveit::planning_interface::MoveGroupInterface::Plan MoveRobot::getCartesianPathPlanToPose(geometry_msgs::Pose target_pose, double eef_step, double jump_threshold)
{
  namespace rvt = rviz_visual_tools;
  move_group->setStartStateToCurrentState();
  std::vector<geometry_msgs::Pose> waypoints;
  waypoints.push_back(move_group->getCurrentPose().pose);
  waypoints.push_back(target_pose);

  moveit_msgs::RobotTrajectory trajectory;
  double fraction=0.0;

  int trial = 0;
  while(fraction<0.5 && trial++<5)
  {
    fraction = move_group->computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
  }
  if(trial == 5 && fraction<0.5)
  {
    ROS_ERROR_STREAM("Could not compute cartesian path for given waypoints, aborting!!");
    ros::shutdown();
    exit(-1);
  }

  //ROS_INFO_STREAM("Visualizing Cartesian Path plan to "  <<  display_label <<" (" << fraction*100  << "% acheived)");

  adjustTrajectoryToFixTimeSequencing(trajectory);

  // Visualize the plan in RViz
  visual_tools->deleteAllMarkers();
  visual_tools->publishText(text_pose, "Cartesian path", rvt::WHITE, rvt::XLARGE);
  for (std::size_t i = 0; i < waypoints.size(); ++i)
    visual_tools->publishAxisLabeled(waypoints[i], "pt" + std::to_string(i), rvt::SMALL);
  visual_tools->trigger();

  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  my_plan.trajectory_ = trajectory;
  return my_plan;

}


void MoveRobot::adjustTrajectoryToFixTimeSequencing(moveit_msgs::RobotTrajectory &trajectory)
{

  std::vector<ros::Duration> times_from_start;
  times_from_start.resize(trajectory.joint_trajectory.points.size());

  for(int i=0; i < times_from_start.size() ; i++)
  {
    times_from_start[i]= trajectory.joint_trajectory.points[i].time_from_start;
//    ROS_INFO_STREAM("P: "  << i<< " time_from_start: " << times_from_start[i]);
  }

//  ROS_INFO_STREAM("Size of time_from_start :" << times_from_start.size() << " trajectory points: " << trajectory.joint_trajectory.points.size());


  // Adjust starting from point 2 i.e. index 1
  bool adjusted_flag=false;
  for(int i=1; i< times_from_start.size()-1;i++)
  {
    if(times_from_start[i]==ros::Duration(0))
    {
      ros::Duration prev = times_from_start[i];
      times_from_start[i] = ros::Duration((times_from_start[i-1].toSec()+times_from_start[i+1].toSec())/2.0);
      ROS_WARN_STREAM("Recomputing point " << i << " from " << prev <<  " to: " << times_from_start[i-1] << " + " << times_from_start[i+1] << " = " <<times_from_start[i]);
      adjusted_flag=true;
    }
  }

  if( times_from_start.size()>1 &&  times_from_start[times_from_start.size()-1] == ros::Duration(0))
  {
    ROS_WARN_STREAM("Final point in trajectory has 0 timestamp, incrementing logically");
    times_from_start[times_from_start.size()-1] = times_from_start[times_from_start.size()-2] + ros::Duration(0.1);
    adjusted_flag=true;
  }

  if(adjusted_flag)
  {
    for(int i=0; i< times_from_start.size(); i++)
    {
      trajectory.joint_trajectory.points[i].time_from_start = times_from_start[i];
//      ROS_INFO_STREAM("Recomputed time point " << i << " : " << trajectory.joint_trajectory.points[i].time_from_start );
    }
  }

}


void MoveRobot::updateStatus(){
    
  if (_status==handover_hand) {
    geometry_msgs::Pose current_pose = move_group->getCurrentPose().pose;
    
    
    if( comparePoses(current_pose, hand_target, 0.05)) {
          
          ROS_INFO_STREAM("On hand position");
          sleepSafeFor(1.0);
          _status=handover_tool;

          
          
          
        } 
  
  }
  if (_status==handover_tool){
    geometry_msgs::Pose current_pose = move_group->getCurrentPose().pose;
    
    
    if( comparePoses(current_pose, tool_target, 0.005)) {
          _status=nominal_task;
          ROS_WARN_STREAM("On tool position");
          sleepSafeFor(3.0);
            
          
          
        } 
  }

}




float MoveRobot::distanceComputing (geometry_msgs::Point point1, geometry_msgs::Point point2){
    float distance;
    
    distance= sqrt(pow(point1.x-point2.x,2)+pow(point1.y-point2.y,2)+pow(point1.z-point2.z,2));
    return distance;
}

void MoveRobot::update_hand_position(tf::StampedTransform transform){
  hand_position_old=hand_position_current;
  geometry_msgs::Point point;
  point.x=transform.getOrigin().x();
  point.y=transform.getOrigin().y();
  point.z=transform.getOrigin().z();
  hand_position_current=point;
}

bool MoveRobot::is_in_the_cell(tf::StampedTransform transform){
  if (transform.getOrigin().x()<WORKCELL_XMAX && transform.getOrigin().x()>WORKCELL_XMIN && transform.getOrigin().y()<WORKCELL_YMAX &&
          transform.getOrigin().y()>WORKCELL_YMIN && transform.getOrigin().z()<WORKCELL_ZMAX && transform.getOrigin().z()>WORKCELL_ZMIN) {
            return true;
          }
  return false;
}

void MoveRobot::update_handover_status(tf::StampedTransform hand_tf, tf::StampedTransform tool_tf){
  if (is_in_the_cell(hand_tf)){
    update_hand_position(hand_tf);
    computePoseToHand();
    if (distanceComputing (hand_position_current,hand_position_old)>hand_tolerance) {
      hand_timer=ros::Time::now();
    }
    if (ros::Time::now()-hand_timer>hand_timer_threshold) {
        if(_status==nominal_task) {
        ROS_WARN_STREAM("handover triggered");
        
        _status=handover_hand;
        //computePoseToHand();
        computePoseToTool(tool_tf);
        }
        
    }
  }
}

enum status MoveRobot::getStatus(){
  return _status;
}


void MoveRobot::computePoseToHand(){
  geometry_msgs::Pose pose;
  pose.position=hand_position_current;
  pose.position.y=pose.position.y-0.15;
  geometry_msgs::Quaternion quat_msg;
  tf::quaternionTFToMsg(tf::createQuaternionFromRPY(angles::from_degrees(-90),angles::from_degrees(0),angles::from_degrees(0)),quat_msg);
  pose.orientation=quat_msg;
  hand_target=pose;
}

void MoveRobot::computePoseToTool(tf::StampedTransform tool_tf){
  geometry_msgs::Pose pose;
  pose.position.x=tool_tf.getOrigin().x();
  pose.position.y=tool_tf.getOrigin().y();
  pose.position.z=tool_tf.getOrigin().z();
  geometry_msgs::Quaternion quat_msg;
  tf::quaternionTFToMsg(tool_tf.getRotation(),quat_msg);
  
  pose.orientation=quat_msg;
  tool_target=pose;
}

geometry_msgs::Pose MoveRobot::getHandTarget(){
  return hand_target;
}

geometry_msgs::Pose MoveRobot::getToolTarget(){
  return tool_target;
}




int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_robot");
  ros::NodeHandle nh;
  tf::StampedTransform transform_hand;
  tf::StampedTransform transform_tool;
  tf::TransformListener hand_listener;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  handover_pub =nh.advertise<std_msgs::Bool>("/handover/approach_flag",1);

  MoveRobot robot_obj;
  robot_obj.initialiseMoveit(nh);
  

  geometry_msgs::Pose target_pose1;
  target_pose1.position.x = 0.3;
  target_pose1.position.y = 0.4; //0.4
  target_pose1.position.z = 0.05;
  geometry_msgs::Quaternion quat_msg;
  tf::quaternionTFToMsg(tf::createQuaternionFromRPY(angles::from_degrees(180),angles::from_degrees(0),angles::from_degrees(0)),quat_msg);
  target_pose1.orientation = quat_msg;

  geometry_msgs::Pose target_pose2 = target_pose1;
  target_pose1.position.x = 0.05;
  int seq = 0;
  bool switcher=true;
 
  robot_obj.executeCartesianTrajtoPose((switcher)?target_pose1:target_pose2);
  while(ros::ok())
  {
  std_msgs::Bool flag;  
  switch(robot_obj.getStatus()){
    case nominal_task :
      flag.data=false;
      handover_pub.publish(flag);
      switcher = !switcher;
      robot_obj.executeCartesianTrajtoPose((switcher)?target_pose1:target_pose2);
      break;

    case handover_hand :
      flag.data=false;
      handover_pub.publish(flag);
      ROS_WARN_STREAM("Go To Hand");    
      robot_obj.executeCartesianTrajtoPose(robot_obj.getHandTarget());
      robot_obj.sleepSafeFor(1.0);
      
      
      break;

    case handover_tool :
      flag.data=true;
      handover_pub.publish(flag);
      robot_obj.executeCartesianTrajtoPose(robot_obj.getToolTarget());
      ROS_WARN_STREAM("Go To Tool");
      robot_obj.sleepSafeFor(1.0);
      
      
      break;
  }
      
      try{
      hand_listener.lookupTransform("/world", "/cam3_link/left_hand",  
                               ros::Time(0), transform_hand);
      hand_listener.lookupTransform("/world", "/tool_grasping_point",  
                               ros::Time(0), transform_tool);               

      robot_obj.update_handover_status(transform_hand, transform_tool);
    }
    catch (tf::TransformException ex){
      //ROS_ERROR("%s",ex.what());
      //ROS_INFO_STREAM("no human skeleton detected");
      //ros::Duration(1.0).sleep();
    }
    robot_obj.updateStatus();

   
    

    
    ros::spinOnce();
    
    
  }
return 0;
}