// Generated by gencpp from file cob_people_detection/loadModelActionGoal.msg
// DO NOT EDIT!


#ifndef COB_PEOPLE_DETECTION_MESSAGE_LOADMODELACTIONGOAL_H
#define COB_PEOPLE_DETECTION_MESSAGE_LOADMODELACTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalID.h>
#include <cob_people_detection/loadModelGoal.h>

namespace cob_people_detection
{
template <class ContainerAllocator>
struct loadModelActionGoal_
{
  typedef loadModelActionGoal_<ContainerAllocator> Type;

  loadModelActionGoal_()
    : header()
    , goal_id()
    , goal()  {
    }
  loadModelActionGoal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , goal_id(_alloc)
    , goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
  _goal_id_type goal_id;

   typedef  ::cob_people_detection::loadModelGoal_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct loadModelActionGoal_

typedef ::cob_people_detection::loadModelActionGoal_<std::allocator<void> > loadModelActionGoal;

typedef boost::shared_ptr< ::cob_people_detection::loadModelActionGoal > loadModelActionGoalPtr;
typedef boost::shared_ptr< ::cob_people_detection::loadModelActionGoal const> loadModelActionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator1> & lhs, const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.goal_id == rhs.goal_id &&
    lhs.goal == rhs.goal;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator1> & lhs, const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cob_people_detection

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ace6be9bc59fc93396f7405a69543564";
  }

  static const char* value(const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xace6be9bc59fc933ULL;
  static const uint64_t static_value2 = 0x96f7405a69543564ULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_people_detection/loadModelActionGoal";
  }

  static const char* value(const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"loadModelGoal goal\n"
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
"MSG: cob_people_detection/loadModelGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Loads a recognition model for the face recognizer from disc or database\n"
"#\n"
"# goal message\n"
"string[] labels		# a list of labels of persons that shall be recognized\n"
;
  }

  static const char* value(const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.goal_id);
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct loadModelActionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_people_detection::loadModelActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_people_detection::loadModelActionGoal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::cob_people_detection::loadModelGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_PEOPLE_DETECTION_MESSAGE_LOADMODELACTIONGOAL_H
