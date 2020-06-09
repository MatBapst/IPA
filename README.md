Fraunhofer IPA
Mathieu Bapst

Seher Project

Robot Human Collaboration

The developed codes and launch files are in the package "seher" and "seher_msgs". "cob_people_perception" has been modified too.

Necessary packages which have to be cloned in your repository :
- cob_perception_common from https://github.com/ipa320/cob_perception_common.git
- fmauch_universal_robot , Universal_Robots_ROS_Driver ur5e_egp50_moveit_config (for ur5e robot) as described on https://github.com/ipa-kut/ur_manipulation. Follow the steps given on the page.
- openni2_camera from https://github.com/ros-drivers/openni2_camera.git
- realsense_ros from https://github.com/IntelRealSense/realsense-ros
- rgbd_launch from https://github.com/ros-drivers/rgbd_launch
- seher_support from https://github.com/ipa-kut/seher_support
- robot_self_filter from https://github.com/PR2/robot_self_filter.git

Install OpenNI2 wrapper for realsense as described in https://github.com/IntelRealSense/librealsense/tree/master/wrappers/openni2 (for human body tracking)




To launch the workcell setup :
- build (catkin_make_isolated necessary) and source the repository
- clone the above given repos.
- roslaunch seher workcell_setup.launch

To run the robot moving demonstration with speed reduction and stopping when approaching :
- rosrun seher move_robot

Hint!! robot has to be in Remote Control mode. This must be activated from Teach Pendant.

SIM BRANCH : working with a gazebo simulated ur5e robot for home setup.

For the home setup :

both cameras are placed in parallel and separetad by 47 cm apporximately

They visualize the scene at a depth of 1.5 m, the scene is cropped and voxelized.

To launch the home setup :

-build and source the repository
- roslaunch seher home_setup.launch to launch all the setup + moveit + distanceCalcualtion node

Then to launch the robot moving node with distance monitoring :
- rosrun seher move_sim_robot (in new terminal)
