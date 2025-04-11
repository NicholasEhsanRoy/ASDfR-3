// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "asdfr_msgs/msg/identified_object.hpp"


#ifndef ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__BUILDER_HPP_
#define ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "asdfr_msgs/msg/detail/identified_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace asdfr_msgs
{

namespace msg
{

namespace builder
{

class Init_IdentifiedObject_r
{
public:
  explicit Init_IdentifiedObject_r(::asdfr_msgs::msg::IdentifiedObject & msg)
  : msg_(msg)
  {}
  ::asdfr_msgs::msg::IdentifiedObject r(::asdfr_msgs::msg::IdentifiedObject::_r_type arg)
  {
    msg_.r = std::move(arg);
    return std::move(msg_);
  }

private:
  ::asdfr_msgs::msg::IdentifiedObject msg_;
};

class Init_IdentifiedObject_y
{
public:
  explicit Init_IdentifiedObject_y(::asdfr_msgs::msg::IdentifiedObject & msg)
  : msg_(msg)
  {}
  Init_IdentifiedObject_r y(::asdfr_msgs::msg::IdentifiedObject::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IdentifiedObject_r(msg_);
  }

private:
  ::asdfr_msgs::msg::IdentifiedObject msg_;
};

class Init_IdentifiedObject_x
{
public:
  Init_IdentifiedObject_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IdentifiedObject_y x(::asdfr_msgs::msg::IdentifiedObject::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IdentifiedObject_y(msg_);
  }

private:
  ::asdfr_msgs::msg::IdentifiedObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::asdfr_msgs::msg::IdentifiedObject>()
{
  return asdfr_msgs::msg::builder::Init_IdentifiedObject_x();
}

}  // namespace asdfr_msgs

#endif  // ASDFR_MSGS__MSG__DETAIL__IDENTIFIED_OBJECT__BUILDER_HPP_
