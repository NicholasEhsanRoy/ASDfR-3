// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "asdfr_msgs/msg/identified_object.hpp"


#ifndef ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__TRAITS_HPP_
#define ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "asdfr_msgs/msg/detail/identified_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace asdfr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IdentifiedObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IdentifiedObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IdentifiedObject & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace asdfr_msgs

namespace rosidl_generator_traits
{

[[deprecated("use asdfr_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const asdfr_msgs::msg::IdentifiedObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  asdfr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use asdfr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const asdfr_msgs::msg::IdentifiedObject & msg)
{
  return asdfr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<asdfr_msgs::msg::IdentifiedObject>()
{
  return "asdfr_msgs::msg::IdentifiedObject";
}

template<>
inline const char * name<asdfr_msgs::msg::IdentifiedObject>()
{
  return "asdfr_msgs/msg/IdentifiedObject";
}

template<>
struct has_fixed_size<asdfr_msgs::msg::IdentifiedObject>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<asdfr_msgs::msg::IdentifiedObject>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<asdfr_msgs::msg::IdentifiedObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__TRAITS_HPP_
