# Install script for directory: /home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/mathieu/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_perception_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/ColorDepthImage.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/ColorDepthImageArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/Detection.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/DetectionArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/Float64ArrayStamped.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/Mask.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/People.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/Person.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/PersonStamped.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/PointCloud2Array.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/PositionMeasurement.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/PositionMeasurementArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/Rect.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/msg/Skeleton.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_perception_msgs/cmake" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_perception_msgs/catkin_generated/installspace/cob_perception_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/include/cob_perception_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/roseus/ros/cob_perception_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/common-lisp/ros/cob_perception_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/gennodejs/ros/cob_perception_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/mathieu/catkin_ws/devel/lib/python2.7/dist-packages/cob_perception_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/lib/python2.7/dist-packages/cob_perception_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_perception_msgs/catkin_generated/installspace/cob_perception_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_perception_msgs/cmake" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_perception_msgs/catkin_generated/installspace/cob_perception_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_perception_msgs/cmake" TYPE FILE FILES
    "/home/mathieu/catkin_ws/build/cob_perception_common/cob_perception_msgs/catkin_generated/installspace/cob_perception_msgsConfig.cmake"
    "/home/mathieu/catkin_ws/build/cob_perception_common/cob_perception_msgs/catkin_generated/installspace/cob_perception_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_perception_msgs" TYPE FILE FILES "/home/mathieu/catkin_ws/src/cob_perception_common/cob_perception_msgs/package.xml")
endif()

