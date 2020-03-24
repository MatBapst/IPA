# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "seher_support: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iseher_support:/home/mathieu/catkin_ws/src/seher_support/msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(seher_support_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" NAME_WE)
add_custom_target(_seher_support_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "seher_support" "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" "geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/PoseStamped:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(seher_support
  "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/seher_support
)

### Generating Services

### Generating Module File
_generate_module_cpp(seher_support
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/seher_support
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(seher_support_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(seher_support_generate_messages seher_support_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" NAME_WE)
add_dependencies(seher_support_generate_messages_cpp _seher_support_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(seher_support_gencpp)
add_dependencies(seher_support_gencpp seher_support_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS seher_support_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(seher_support
  "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/seher_support
)

### Generating Services

### Generating Module File
_generate_module_eus(seher_support
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/seher_support
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(seher_support_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(seher_support_generate_messages seher_support_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" NAME_WE)
add_dependencies(seher_support_generate_messages_eus _seher_support_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(seher_support_geneus)
add_dependencies(seher_support_geneus seher_support_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS seher_support_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(seher_support
  "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/seher_support
)

### Generating Services

### Generating Module File
_generate_module_lisp(seher_support
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/seher_support
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(seher_support_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(seher_support_generate_messages seher_support_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" NAME_WE)
add_dependencies(seher_support_generate_messages_lisp _seher_support_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(seher_support_genlisp)
add_dependencies(seher_support_genlisp seher_support_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS seher_support_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(seher_support
  "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/seher_support
)

### Generating Services

### Generating Module File
_generate_module_nodejs(seher_support
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/seher_support
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(seher_support_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(seher_support_generate_messages seher_support_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" NAME_WE)
add_dependencies(seher_support_generate_messages_nodejs _seher_support_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(seher_support_gennodejs)
add_dependencies(seher_support_gennodejs seher_support_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS seher_support_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(seher_support
  "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/seher_support
)

### Generating Services

### Generating Module File
_generate_module_py(seher_support
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/seher_support
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(seher_support_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(seher_support_generate_messages seher_support_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mathieu/catkin_ws/src/seher_support/msg/PoseStampedArray.msg" NAME_WE)
add_dependencies(seher_support_generate_messages_py _seher_support_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(seher_support_genpy)
add_dependencies(seher_support_genpy seher_support_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS seher_support_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/seher_support)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/seher_support
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(seher_support_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/seher_support)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/seher_support
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(seher_support_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/seher_support)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/seher_support
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(seher_support_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/seher_support)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/seher_support
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(seher_support_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/seher_support)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/seher_support\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/seher_support
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(seher_support_generate_messages_py geometry_msgs_generate_messages_py)
endif()
