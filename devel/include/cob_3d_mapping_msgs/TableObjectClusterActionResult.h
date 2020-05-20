// Generated by gencpp from file cob_3d_mapping_msgs/TableObjectClusterActionResult.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_TABLEOBJECTCLUSTERACTIONRESULT_H
#define COB_3D_MAPPING_MSGS_MESSAGE_TABLEOBJECTCLUSTERACTIONRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalStatus.h>
#include <cob_3d_mapping_msgs/TableObjectClusterResult.h>

namespace cob_3d_mapping_msgs
{
template <class ContainerAllocator>
struct TableObjectClusterActionResult_
{
  typedef TableObjectClusterActionResult_<ContainerAllocator> Type;

  TableObjectClusterActionResult_()
    : header()
    , status()
    , result()  {
    }
  TableObjectClusterActionResult_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , status(_alloc)
    , result(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalStatus_<ContainerAllocator>  _status_type;
  _status_type status;

   typedef  ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator>  _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> const> ConstPtr;

}; // struct TableObjectClusterActionResult_

typedef ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<std::allocator<void> > TableObjectClusterActionResult;

typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterActionResult > TableObjectClusterActionResultPtr;
typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterActionResult const> TableObjectClusterActionResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator1> & lhs, const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.status == rhs.status &&
    lhs.result == rhs.result;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator1> & lhs, const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cob_3d_mapping_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e9a500864cad0f17b191d7e31020df77";
  }

  static const char* value(const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe9a500864cad0f17ULL;
  static const uint64_t static_value2 = 0xb191d7e31020df77ULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_3d_mapping_msgs/TableObjectClusterActionResult";
  }

  static const char* value(const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"TableObjectClusterResult result\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalStatus\n"
"GoalID goal_id\n"
"uint8 status\n"
"uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n"
"uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n"
"uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n"
"                            #   and has since completed its execution (Terminal State)\n"
"uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n"
"uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n"
"                            #    to some failure (Terminal State)\n"
"uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n"
"                            #    because the goal was unattainable or invalid (Terminal State)\n"
"uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n"
"                            #    and has not yet completed execution\n"
"uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n"
"                            #    but the action server has not yet confirmed that the goal is canceled\n"
"uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n"
"                            #    and was successfully cancelled (Terminal State)\n"
"uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n"
"                            #    sent over the wire by an action server\n"
"\n"
"#Allow for the user to associate a string with GoalStatus for debugging\n"
"string text\n"
"\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalID\n"
"# The stamp should store the time at which this goal was requested.\n"
"# It is used by an action server when it tries to preempt all\n"
"# goals that were requested before a certain time\n"
"time stamp\n"
"\n"
"# The id provides a way to associate feedback and\n"
"# result message with specific goal requests. The id\n"
"# specified must be unique.\n"
"string id\n"
"\n"
"\n"
"================================================================================\n"
"MSG: cob_3d_mapping_msgs/TableObjectClusterResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#result definition\n"
"cob_object_detection_msgs/DetectionArray bounding_boxes\n"
"\n"
"================================================================================\n"
"MSG: cob_object_detection_msgs/DetectionArray\n"
"Header header\n"
"Detection[] detections\n"
"\n"
"================================================================================\n"
"MSG: cob_object_detection_msgs/Detection\n"
"Header header\n"
"string label\n"
"int32 id\n"
"string detector\n"
"float32 score\n"
"Mask mask\n"
"geometry_msgs/PoseStamped pose\n"
"geometry_msgs/Point bounding_box_lwh\n"
"\n"
"================================================================================\n"
"MSG: cob_object_detection_msgs/Mask\n"
"# this message is used to mark where an object is present in an image\n"
"# this can be done either by a roi region on the image (less precise) or a mask (more precise)\n"
"\n"
"Rect roi\n"
"\n"
"# in the case when mask is used, 'roi' specifies the image region and 'mask'\n"
"# (which should be of the same size) a binary mask in that region\n"
"sensor_msgs/Image mask\n"
"\n"
"# in the case there is 3D data available, 'indices' are used to index the \n"
"# part of the point cloud representing the object\n"
"#pcl/PointIndices indices\n"
"\n"
"================================================================================\n"
"MSG: cob_object_detection_msgs/Rect\n"
"int32 x\n"
"int32 y\n"
"int32 width\n"
"int32 height\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/Image\n"
"# This message contains an uncompressed image\n"
"# (0, 0) is at top-left corner of image\n"
"#\n"
"\n"
"Header header        # Header timestamp should be acquisition time of image\n"
"                     # Header frame_id should be optical frame of camera\n"
"                     # origin of frame should be optical center of camera\n"
"                     # +x should point to the right in the image\n"
"                     # +y should point down in the image\n"
"                     # +z should point into to plane of the image\n"
"                     # If the frame_id here and the frame_id of the CameraInfo\n"
"                     # message associated with the image conflict\n"
"                     # the behavior is undefined\n"
"\n"
"uint32 height         # image height, that is, number of rows\n"
"uint32 width          # image width, that is, number of columns\n"
"\n"
"# The legal values for encoding are in file src/image_encodings.cpp\n"
"# If you want to standardize a new string format, join\n"
"# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n"
"\n"
"string encoding       # Encoding of pixels -- channel meaning, ordering, size\n"
"                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n"
"\n"
"uint8 is_bigendian    # is this data bigendian?\n"
"uint32 step           # Full row length in bytes\n"
"uint8[] data          # actual matrix data, size is (step * rows)\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.status);
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TableObjectClusterActionResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_3d_mapping_msgs::TableObjectClusterActionResult_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "status: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalStatus_<ContainerAllocator> >::stream(s, indent + "  ", v.status);
    s << indent << "result: ";
    s << std::endl;
    Printer< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_TABLEOBJECTCLUSTERACTIONRESULT_H
