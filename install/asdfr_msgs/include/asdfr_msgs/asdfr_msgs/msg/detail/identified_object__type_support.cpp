// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "asdfr_msgs/msg/detail/identified_object__functions.h"
#include "asdfr_msgs/msg/detail/identified_object__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace asdfr_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IdentifiedObject_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) asdfr_msgs::msg::IdentifiedObject(_init);
}

void IdentifiedObject_fini_function(void * message_memory)
{
  auto typed_message = static_cast<asdfr_msgs::msg::IdentifiedObject *>(message_memory);
  typed_message->~IdentifiedObject();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IdentifiedObject_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(asdfr_msgs::msg::IdentifiedObject, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(asdfr_msgs::msg::IdentifiedObject, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "r",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(asdfr_msgs::msg::IdentifiedObject, r),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IdentifiedObject_message_members = {
  "asdfr_msgs::msg",  // message namespace
  "IdentifiedObject",  // message name
  3,  // number of fields
  sizeof(asdfr_msgs::msg::IdentifiedObject),
  false,  // has_any_key_member_
  IdentifiedObject_message_member_array,  // message members
  IdentifiedObject_init_function,  // function to initialize message memory (memory has to be allocated)
  IdentifiedObject_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IdentifiedObject_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IdentifiedObject_message_members,
  get_message_typesupport_handle_function,
  &asdfr_msgs__msg__IdentifiedObject__get_type_hash,
  &asdfr_msgs__msg__IdentifiedObject__get_type_description,
  &asdfr_msgs__msg__IdentifiedObject__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace asdfr_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<asdfr_msgs::msg::IdentifiedObject>()
{
  return &::asdfr_msgs::msg::rosidl_typesupport_introspection_cpp::IdentifiedObject_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, asdfr_msgs, msg, IdentifiedObject)() {
  return &::asdfr_msgs::msg::rosidl_typesupport_introspection_cpp::IdentifiedObject_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
