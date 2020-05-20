// Generated by gencpp from file cob_object_detection_msgs/BagTrainObjectRequest.msg
// DO NOT EDIT!


#ifndef COB_OBJECT_DETECTION_MSGS_MESSAGE_BAGTRAINOBJECTREQUEST_H
#define COB_OBJECT_DETECTION_MSGS_MESSAGE_BAGTRAINOBJECTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/String.h>

namespace cob_object_detection_msgs
{
template <class ContainerAllocator>
struct BagTrainObjectRequest_
{
  typedef BagTrainObjectRequest_<ContainerAllocator> Type;

  BagTrainObjectRequest_()
    : object_name()  {
    }
  BagTrainObjectRequest_(const ContainerAllocator& _alloc)
    : object_name(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::String_<ContainerAllocator>  _object_name_type;
  _object_name_type object_name;





  typedef boost::shared_ptr< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> const> ConstPtr;

}; // struct BagTrainObjectRequest_

typedef ::cob_object_detection_msgs::BagTrainObjectRequest_<std::allocator<void> > BagTrainObjectRequest;

typedef boost::shared_ptr< ::cob_object_detection_msgs::BagTrainObjectRequest > BagTrainObjectRequestPtr;
typedef boost::shared_ptr< ::cob_object_detection_msgs::BagTrainObjectRequest const> BagTrainObjectRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator1> & lhs, const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator2> & rhs)
{
  return lhs.object_name == rhs.object_name;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator1> & lhs, const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cob_object_detection_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "adb33ef101026c3e15d799e3decf403f";
  }

  static const char* value(const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xadb33ef101026c3eULL;
  static const uint64_t static_value2 = 0x15d799e3decf403fULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_object_detection_msgs/BagTrainObjectRequest";
  }

  static const char* value(const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/String object_name\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/String\n"
"string data\n"
;
  }

  static const char* value(const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.object_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct BagTrainObjectRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_object_detection_msgs::BagTrainObjectRequest_<ContainerAllocator>& v)
  {
    s << indent << "object_name: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.object_name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_OBJECT_DETECTION_MSGS_MESSAGE_BAGTRAINOBJECTREQUEST_H
