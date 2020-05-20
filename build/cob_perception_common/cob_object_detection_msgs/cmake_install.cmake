# Install script for directory: /home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/action" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/action/AcquireObjectImage.action"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/action/DetectObjects.action"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/action/TrainObject.action"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageAction.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageActionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageActionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageActionFeedback.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/AcquireObjectImageFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsAction.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsActionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsActionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsActionFeedback.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/DetectObjectsFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectAction.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectActionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectActionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectActionFeedback.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_object_detection_msgs/msg/TrainObjectFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/Detection.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/DetectionArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/Mask.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/MaskArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/PoseRT.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/Rect.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/msg/RectArray.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/srv" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/AcquireObjectImage.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/BaTestEnvironment.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/BagTrainObject.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/DetectObjects.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/SaveRecordedObject.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/StartObjectRecording.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/StopObjectRecording.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/srv/TrainObject.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/cmake" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_object_detection_msgs/catkin_generated/installspace/cob_object_detection_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/include/cob_object_detection_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/roseus/ros/cob_object_detection_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/common-lisp/ros/cob_object_detection_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/gennodejs/ros/cob_object_detection_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/mathieu/catkin_ws/devel/lib/python2.7/dist-packages/cob_object_detection_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/lib/python2.7/dist-packages/cob_object_detection_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_object_detection_msgs/catkin_generated/installspace/cob_object_detection_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/cmake" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_object_detection_msgs/catkin_generated/installspace/cob_object_detection_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs/cmake" TYPE FILE FILES
    "/home/mathieu/catkin_ws/build/cob_perception_common/cob_object_detection_msgs/catkin_generated/installspace/cob_object_detection_msgsConfig.cmake"
    "/home/mathieu/catkin_ws/build/cob_perception_common/cob_object_detection_msgs/catkin_generated/installspace/cob_object_detection_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_object_detection_msgs" TYPE FILE FILES "/home/mathieu/catkin_ws/src/cob_perception_common/cob_object_detection_msgs/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cob_object_detection_msgs" TYPE PROGRAM FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_object_detection_msgs/catkin_generated/installspace/detection_component_testing.py")
endif()

