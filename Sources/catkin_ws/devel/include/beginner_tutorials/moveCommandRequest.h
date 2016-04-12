// Generated by gencpp from file beginner_tutorials/moveCommandRequest.msg
// DO NOT EDIT!


#ifndef BEGINNER_TUTORIALS_MESSAGE_MOVECOMMANDREQUEST_H
#define BEGINNER_TUTORIALS_MESSAGE_MOVECOMMANDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace beginner_tutorials
{
template <class ContainerAllocator>
struct moveCommandRequest_
{
  typedef moveCommandRequest_<ContainerAllocator> Type;

  moveCommandRequest_()
    : dir1()
    , dir2()
    , speed(0)  {
    }
  moveCommandRequest_(const ContainerAllocator& _alloc)
    : dir1(_alloc)
    , dir2(_alloc)
    , speed(0)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dir1_type;
  _dir1_type dir1;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dir2_type;
  _dir2_type dir2;

   typedef int64_t _speed_type;
  _speed_type speed;




  typedef boost::shared_ptr< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> const> ConstPtr;

}; // struct moveCommandRequest_

typedef ::beginner_tutorials::moveCommandRequest_<std::allocator<void> > moveCommandRequest;

typedef boost::shared_ptr< ::beginner_tutorials::moveCommandRequest > moveCommandRequestPtr;
typedef boost::shared_ptr< ::beginner_tutorials::moveCommandRequest const> moveCommandRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace beginner_tutorials

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'beginner_tutorials': ['/home/julien/catkin_ws/src/beginner_tutorials/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a50a09b91c7a92144f2d7b44d1768ebd";
  }

  static const char* value(const ::beginner_tutorials::moveCommandRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa50a09b91c7a9214ULL;
  static const uint64_t static_value2 = 0x4f2d7b44d1768ebdULL;
};

template<class ContainerAllocator>
struct DataType< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "beginner_tutorials/moveCommandRequest";
  }

  static const char* value(const ::beginner_tutorials::moveCommandRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string dir1\n\
string dir2\n\
int64 speed\n\
";
  }

  static const char* value(const ::beginner_tutorials::moveCommandRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dir1);
      stream.next(m.dir2);
      stream.next(m.speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct moveCommandRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::beginner_tutorials::moveCommandRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::beginner_tutorials::moveCommandRequest_<ContainerAllocator>& v)
  {
    s << indent << "dir1: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dir1);
    s << indent << "dir2: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dir2);
    s << indent << "speed: ";
    Printer<int64_t>::stream(s, indent + "  ", v.speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEGINNER_TUTORIALS_MESSAGE_MOVECOMMANDREQUEST_H
