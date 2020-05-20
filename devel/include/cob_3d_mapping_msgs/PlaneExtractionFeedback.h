// Generated by gencpp from file cob_3d_mapping_msgs/PlaneExtractionFeedback.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_PLANEEXTRACTIONFEEDBACK_H
#define COB_3D_MAPPING_MSGS_MESSAGE_PLANEEXTRACTIONFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/String.h>

namespace cob_3d_mapping_msgs
{
template <class ContainerAllocator>
struct PlaneExtractionFeedback_
{
  typedef PlaneExtractionFeedback_<ContainerAllocator> Type;

  PlaneExtractionFeedback_()
    : currentStep()  {
    }
  PlaneExtractionFeedback_(const ContainerAllocator& _alloc)
    : currentStep(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::String_<ContainerAllocator>  _currentStep_type;
  _currentStep_type currentStep;





  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct PlaneExtractionFeedback_

typedef ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<std::allocator<void> > PlaneExtractionFeedback;

typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionFeedback > PlaneExtractionFeedbackPtr;
typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionFeedback const> PlaneExtractionFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator1> & lhs, const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator2> & rhs)
{
  return lhs.currentStep == rhs.currentStep;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator1> & lhs, const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cob_3d_mapping_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7c51960fbfdc31dbfce9bf929242f080";
  }

  static const char* value(const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7c51960fbfdc31dbULL;
  static const uint64_t static_value2 = 0xfce9bf929242f080ULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_3d_mapping_msgs/PlaneExtractionFeedback";
  }

  static const char* value(const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#feedback\n"
"std_msgs/String currentStep\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/String\n"
"string data\n"
;
  }

  static const char* value(const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.currentStep);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PlaneExtractionFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_3d_mapping_msgs::PlaneExtractionFeedback_<ContainerAllocator>& v)
  {
    s << indent << "currentStep: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.currentStep);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_PLANEEXTRACTIONFEEDBACK_H
