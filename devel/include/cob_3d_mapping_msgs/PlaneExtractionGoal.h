// Generated by gencpp from file cob_3d_mapping_msgs/PlaneExtractionGoal.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_PLANEEXTRACTIONGOAL_H
#define COB_3D_MAPPING_MSGS_MESSAGE_PLANEEXTRACTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cob_3d_mapping_msgs
{
template <class ContainerAllocator>
struct PlaneExtractionGoal_
{
  typedef PlaneExtractionGoal_<ContainerAllocator> Type;

  PlaneExtractionGoal_()
    {
    }
  PlaneExtractionGoal_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct PlaneExtractionGoal_

typedef ::cob_3d_mapping_msgs::PlaneExtractionGoal_<std::allocator<void> > PlaneExtractionGoal;

typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionGoal > PlaneExtractionGoalPtr;
typedef boost::shared_ptr< ::cob_3d_mapping_msgs::PlaneExtractionGoal const> PlaneExtractionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace cob_3d_mapping_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_3d_mapping_msgs/PlaneExtractionGoal";
  }

  static const char* value(const ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#Trigger Plane Extraction\n"
"#goal definition\n"
;
  }

  static const char* value(const ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PlaneExtractionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::cob_3d_mapping_msgs::PlaneExtractionGoal_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_PLANEEXTRACTIONGOAL_H
