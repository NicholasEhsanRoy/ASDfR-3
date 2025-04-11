// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "asdfr_msgs/msg/identified_object.h"


#ifndef ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__STRUCT_H_
#define ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/IdentifiedObject in the package asdfr_msgs.
typedef struct asdfr_msgs__msg__IdentifiedObject
{
  int32_t x;
  int32_t y;
  double r;
} asdfr_msgs__msg__IdentifiedObject;

// Struct for a sequence of asdfr_msgs__msg__IdentifiedObject.
typedef struct asdfr_msgs__msg__IdentifiedObject__Sequence
{
  asdfr_msgs__msg__IdentifiedObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} asdfr_msgs__msg__IdentifiedObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__STRUCT_H_
