#include "seher/move_sim_robot/move_sim_robot.h"
#include "tf/transform_datatypes.h"
#include <angles/angles.h>
#include <std_msgs/Header.h>
#include <std_msgs/Int64.h>


//constructor
MoveRobot::MoveRobot()
{

}

//Destructor
MoveRobot::~MoveRobot() {}

void MoveRobot::initialiseMoveit(ros::NodeHandle nh)
{
  namespace rvt = rviz_visual_tools;
  move_group = new moveit::planning_interface::MoveGroupInterface(GROUP_MANIP);
  joint_model_group = move_group->getCurrentState()->getJointModelGroup(GROUP_MANIP);
  
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


void MoveRobot::executeCartesianTrajtoPose(geometry_msgs::Pose target, std::string label)
{
  int trial=0;
  while(trial<5)
  {
    if(moveGroupExecutePlan(getCartesianPathPlanToPose(target, label)))
    {
      return;
    }
    ROS_ERROR_STREAM("Execution to " << label << " trial " << trial++ << " failed. Reattempting");
    //failure_counter_++;
  }
  ROS_ERROR_STREAM("Maxx execution attempts reached, aborting program");
  ros::shutdown();
  exit(-1);
}


bool MoveRobot::moveGroupExecutePlan(moveit::planning_interface::MoveGroupInterface::Plan my_plan)
{

  /*if(user_prompts)
  {
    std::string message = "Planning completed, press Next to execute";
    visual_tools->prompt(message);
  }
  */
  move_group->setStartStateToCurrentState();
  
  return move_group->execute(my_plan)==moveit::planning_interface::MoveItErrorCode::SUCCESS;;
}


moveit::planning_interface::MoveGroupInterface::Plan MoveRobot::getCartesianPathPlanToPose(geometry_msgs::Pose target_pose, std::string display_label, double eef_step, double jump_threshold)
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

  ROS_INFO_STREAM("Visualizing Cartesian Path plan to "  <<  display_label <<" (" << fraction*100  << "% acheived)");

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



int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_robot");
  ros::NodeHandle nh;
  ros::AsyncSpinner spinner(1);
  spinner.start();

/*
  ros::Publisher planning_scene_diff_publisher = nh.advertise<moveit_msgs::PlanningScene>("planning_scene", 1);
  ros::Publisher pub_seq = nh.advertise<std_msgs::Header>("/ur_manipulation/sequence",1);
  ros::Publisher pub_fail = nh.advertise<std_msgs::Header>("/ur_manipulation/failure_counter",1);
  */

  MoveRobot robot_obj;
  robot_obj.initialiseMoveit(nh);
  /*seher_obj.printBasicInfo();
  ROS_INFO("---------------------------");
  //seher_obj.addCollissionObjects();
  ROS_INFO("Moving to home pose");
  seher_obj.moveToNamedTarget("home");

  ROS_INFO("Starting PnP");
  ROS_INFO("---------------------------");
  */

    geometry_msgs::Pose target_pose1;
  target_pose1.position.x = 0.3;
  target_pose1.position.y = 0.4;
  target_pose1.position.z = 0.4;
  geometry_msgs::Quaternion quat_msg;
  tf::quaternionTFToMsg(tf::createQuaternionFromRPY(angles::from_degrees(-90),angles::from_degrees(0),angles::from_degrees(0)),quat_msg);
  target_pose1.orientation = quat_msg;

  geometry_msgs::Pose target_pose2 = target_pose1;
  target_pose1.position.x = 0.05;
  int seq = 0;
  bool switcher=false;
  
  while(ros::ok())
  {
    ROS_INFO_STREAM("----------------------SEQ " << seq << "-------------------------------------");
    robot_obj.executeCartesianTrajtoPose((switcher)?target_pose1:target_pose2, "To Point A");
    robot_obj.sleepSafeFor(1);
    robot_obj.executeCartesianTrajtoPose((switcher)?target_pose2:target_pose1, "To Point B");
    robot_obj.sleepSafeFor(1);
    switcher = !switcher;
    /*if (!switcher){
      ROS_INFO_STREAM("Slow down");
      seher_obj.move_group->setMaxVelocityScalingFactor(0.05);
    } else{
      ROS_INFO_STREAM("nominal speed");
      seher_obj.move_group->setMaxVelocityScalingFactor(1);
    }*/
    
  }
return 0;
}