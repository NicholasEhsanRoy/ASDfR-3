// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice

#include "asdfr_msgs/msg/detail/identified_object__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_asdfr_msgs
const rosidl_type_hash_t *
asdfr_msgs__msg__IdentifiedObject__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x59, 0x2c, 0xfc, 0xbf, 0x8c, 0x34, 0x3d, 0x5f,
      0x69, 0x3b, 0x3d, 0xdc, 0xe8, 0x64, 0xc1, 0x25,
      0xeb, 0x33, 0xd5, 0x50, 0x9f, 0x6b, 0xac, 0xcb,
      0xbe, 0x36, 0xca, 0xee, 0xa9, 0x25, 0x88, 0x62,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char asdfr_msgs__msg__IdentifiedObject__TYPE_NAME[] = "asdfr_msgs/msg/IdentifiedObject";

// Define type names, field names, and default values
static char asdfr_msgs__msg__IdentifiedObject__FIELD_NAME__x[] = "x";
static char asdfr_msgs__msg__IdentifiedObject__FIELD_NAME__y[] = "y";
static char asdfr_msgs__msg__IdentifiedObject__FIELD_NAME__r[] = "r";

static rosidl_runtime_c__type_description__Field asdfr_msgs__msg__IdentifiedObject__FIELDS[] = {
  {
    {asdfr_msgs__msg__IdentifiedObject__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {asdfr_msgs__msg__IdentifiedObject__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {asdfr_msgs__msg__IdentifiedObject__FIELD_NAME__r, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
asdfr_msgs__msg__IdentifiedObject__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {asdfr_msgs__msg__IdentifiedObject__TYPE_NAME, 31, 31},
      {asdfr_msgs__msg__IdentifiedObject__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 x\n"
  "int32 y\n"
  "float64 r";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
asdfr_msgs__msg__IdentifiedObject__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {asdfr_msgs__msg__IdentifiedObject__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 25, 25},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
asdfr_msgs__msg__IdentifiedObject__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *asdfr_msgs__msg__IdentifiedObject__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
