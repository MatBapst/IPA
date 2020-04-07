#ifndef MOVE_SIM_ROBOT_H
#define MOVE_SIM_ROBOT_H

//Includes
#include "ros/ros.h"

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene/planning_scene.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <geometry_msgs/PoseStamped.h>

#include "ur_msgs/SetIO.h"


class MoveRobot {


public:
MoveRobot();
~MoveRobot();

const std::string GROUP_MANIP = "manipulator";

moveit::planning_interface::MoveGroupInterface *move_group;

//methods
void initialiseMoveit(ros::NodeHandle nh);
bool comparePoses(geometry_msgs::Pose pose1, geometry_msgs::Pose pose2, double delta_posistion=0.05, double delta_orientation=0.01);
void sleepSafeFor(double duration);
void executeCartesianTrajtoPose(geometry_msgs::Pose target, std::string label);
bool moveGroupExecutePlan(moveit::planning_interface::MoveGroupInterface::Plan my_plan);
moveit::planning_interface::MoveGroupInterface::Plan getCartesianPathPlanToPose(geometry_msgs::Pose target_pose, std::string display_label, double eef_step=0.01, double jump_threshold = 0.0);

void adjustTrajectoryToFixTimeSequencing(moveit_msgs::RobotTrajectory &trajectory);

private:

moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
const robot_state::JointModelGroup* joint_model_group ;
moveit_visual_tools::MoveItVisualTools *visual_tools;
Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
const int IO_SERVICE_FUN_LEVEL_ = 1;   // Not exactly sure what this is, but 1 seems to work. If it fails, try 2.




};

#endif