# Install script for directory: /home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/action" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/action/PlaneExtraction.action"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/action/TableObjectCluster.action"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/action/Trigger.action"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionAction.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionActionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionActionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionActionFeedback.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/PlaneExtractionFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterAction.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterActionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterActionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterActionFeedback.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TableObjectClusterFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerAction.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerActionGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerActionResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerActionFeedback.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerGoal.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerResult.msg"
    "/home/mathieu/catkin_ws/devel/share/cob_3d_mapping_msgs/msg/TriggerFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/msg" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/CurvedPolygon.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/CurvedPolygonArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/Feature.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/FilterObject.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/Plane.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/PlaneScene.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/Point2D.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/Polygon.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/PolylinePoint.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/Shape.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/ShapeArray.msg"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg/SimilarityScore.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/srv" TYPE FILE FILES
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetApproachPoseForPolygon.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetBoundingBoxes.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetGeometryMap.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetObjectsOfClass.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetPlane.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetPointMap.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/GetTables.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/ModifyMap.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/MoveToTable.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/SetBoundingBoxes.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/SetGeometryMap.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/SetPointMap.srv"
    "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/srv/UpdateMap.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/cmake" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_3d_mapping_msgs/catkin_generated/installspace/cob_3d_mapping_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/include/cob_3d_mapping_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/roseus/ros/cob_3d_mapping_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/common-lisp/ros/cob_3d_mapping_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/share/gennodejs/ros/cob_3d_mapping_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/mathieu/catkin_ws/devel/lib/python2.7/dist-packages/cob_3d_mapping_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/mathieu/catkin_ws/devel/lib/python2.7/dist-packages/cob_3d_mapping_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_3d_mapping_msgs/catkin_generated/installspace/cob_3d_mapping_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/cmake" TYPE FILE FILES "/home/mathieu/catkin_ws/build/cob_perception_common/cob_3d_mapping_msgs/catkin_generated/installspace/cob_3d_mapping_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs/cmake" TYPE FILE FILES
    "/home/mathieu/catkin_ws/build/cob_perception_common/cob_3d_mapping_msgs/catkin_generated/installspace/cob_3d_mapping_msgsConfig.cmake"
    "/home/mathieu/catkin_ws/build/cob_perception_common/cob_3d_mapping_msgs/catkin_generated/installspace/cob_3d_mapping_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cob_3d_mapping_msgs" TYPE FILE FILES "/home/mathieu/catkin_ws/src/cob_perception_common/cob_3d_mapping_msgs/package.xml")
endif()

