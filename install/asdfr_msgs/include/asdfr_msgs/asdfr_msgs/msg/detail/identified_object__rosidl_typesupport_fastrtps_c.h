// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice
#ifndef ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "asdfr_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "asdfr_msgs/msg/detail/identified_object__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
bool cdr_serialize_asdfr_msgs__msg__IdentifiedObject(
  const asdfr_msgs__msg__IdentifiedObject * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
bool cdr_deserialize_asdfr_msgs__msg__IdentifiedObject(
  eprosima::fastcdr::Cdr &,
  asdfr_msgs__msg__IdentifiedObject * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
size_t get_serialized_size_asdfr_msgs__msg__IdentifiedObject(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
size_t max_serialized_size_asdfr_msgs__msg__IdentifiedObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
bool cdr_serialize_key_asdfr_msgs__msg__IdentifiedObject(
  const asdfr_msgs__msg__IdentifiedObject * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
size_t get_serialized_size_key_asdfr_msgs__msg__IdentifiedObject(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
size_t max_serialized_size_key_asdfr_msgs__msg__IdentifiedObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_asdfr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, asdfr_msgs, msg, IdentifiedObject)();

#ifdef __cplusplus
}
#endif

#endif  // ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
