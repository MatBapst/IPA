# CMake generated Testfile for 
# Source directory: /home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller
# Build directory: /home/mathieu/catkin_ws/build/ros_controllers/joint_trajectory_controller
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_joint_trajectory_controller_gtest_quintic_spline_segment_test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-quintic_spline_segment_test.xml" "--return-code" "/home/mathieu/catkin_ws/devel/lib/joint_trajectory_controller/quintic_spline_segment_test --gtest_output=xml:/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-quintic_spline_segment_test.xml")
add_test(_ctest_joint_trajectory_controller_gtest_trajectory_interface_test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-trajectory_interface_test.xml" "--return-code" "/home/mathieu/catkin_ws/devel/lib/joint_trajectory_controller/trajectory_interface_test --gtest_output=xml:/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-trajectory_interface_test.xml")
add_test(_ctest_joint_trajectory_controller_gtest_joint_trajectory_segment_test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-joint_trajectory_segment_test.xml" "--return-code" "/home/mathieu/catkin_ws/devel/lib/joint_trajectory_controller/joint_trajectory_segment_test --gtest_output=xml:/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-joint_trajectory_segment_test.xml")
add_test(_ctest_joint_trajectory_controller_gtest_joint_trajectory_msg_utils_test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-joint_trajectory_msg_utils_test.xml" "--return-code" "/home/mathieu/catkin_ws/devel/lib/joint_trajectory_controller/joint_trajectory_msg_utils_test --gtest_output=xml:/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-joint_trajectory_msg_utils_test.xml")
add_test(_ctest_joint_trajectory_controller_gtest_init_joint_trajectory_test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-init_joint_trajectory_test.xml" "--return-code" "/home/mathieu/catkin_ws/devel/lib/joint_trajectory_controller/init_joint_trajectory_test --gtest_output=xml:/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/gtest-init_joint_trajectory_test.xml")
add_test(_ctest_joint_trajectory_controller_rostest_test_tolerances.test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/rostest-test_tolerances.xml" "--return-code" "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller --package=joint_trajectory_controller --results-filename test_tolerances.xml --results-base-dir \"/home/mathieu/catkin_ws/build/test_results\" /home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller/test/tolerances.test ")
add_test(_ctest_joint_trajectory_controller_rostest_test_joint_trajectory_controller.test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/rostest-test_joint_trajectory_controller.xml" "--return-code" "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller --package=joint_trajectory_controller --results-filename test_joint_trajectory_controller.xml --results-base-dir \"/home/mathieu/catkin_ws/build/test_results\" /home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller/test/joint_trajectory_controller.test ")
add_test(_ctest_joint_trajectory_controller_rostest_test_joint_trajectory_controller_stopramp.test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/rostest-test_joint_trajectory_controller_stopramp.xml" "--return-code" "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller --package=joint_trajectory_controller --results-filename test_joint_trajectory_controller_stopramp.xml --results-base-dir \"/home/mathieu/catkin_ws/build/test_results\" /home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller/test/joint_trajectory_controller_stopramp.test ")
add_test(_ctest_joint_trajectory_controller_rostest_test_joint_trajectory_controller_vel.test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/rostest-test_joint_trajectory_controller_vel.xml" "--return-code" "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller --package=joint_trajectory_controller --results-filename test_joint_trajectory_controller_vel.xml --results-base-dir \"/home/mathieu/catkin_ws/build/test_results\" /home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller/test/joint_trajectory_controller_vel.test ")
add_test(_ctest_joint_trajectory_controller_rostest_test_joint_trajectory_controller_wrapping.test "/home/mathieu/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mathieu/catkin_ws/build/test_results/joint_trajectory_controller/rostest-test_joint_trajectory_controller_wrapping.xml" "--return-code" "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller --package=joint_trajectory_controller --results-filename test_joint_trajectory_controller_wrapping.xml --results-base-dir \"/home/mathieu/catkin_ws/build/test_results\" /home/mathieu/catkin_ws/src/ros_controllers/joint_trajectory_controller/test/joint_trajectory_controller_wrapping.test ")
