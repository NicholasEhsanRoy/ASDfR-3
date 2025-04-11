// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from asdfr_msgs:msg/IdentifiedObject.idl
// generated code does not contain a copyright notice
#include "asdfr_msgs/msg/detail/identified_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
asdfr_msgs__msg__IdentifiedObject__init(asdfr_msgs__msg__IdentifiedObject * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // r
  return true;
}

void
asdfr_msgs__msg__IdentifiedObject__fini(asdfr_msgs__msg__IdentifiedObject * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // r
}

bool
asdfr_msgs__msg__IdentifiedObject__are_equal(const asdfr_msgs__msg__IdentifiedObject * lhs, const asdfr_msgs__msg__IdentifiedObject * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // r
  if (lhs->r != rhs->r) {
    return false;
  }
  return true;
}

bool
asdfr_msgs__msg__IdentifiedObject__copy(
  const asdfr_msgs__msg__IdentifiedObject * input,
  asdfr_msgs__msg__IdentifiedObject * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // r
  output->r = input->r;
  return true;
}

asdfr_msgs__msg__IdentifiedObject *
asdfr_msgs__msg__IdentifiedObject__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  asdfr_msgs__msg__IdentifiedObject * msg = (asdfr_msgs__msg__IdentifiedObject *)allocator.allocate(sizeof(asdfr_msgs__msg__IdentifiedObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(asdfr_msgs__msg__IdentifiedObject));
  bool success = asdfr_msgs__msg__IdentifiedObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
asdfr_msgs__msg__IdentifiedObject__destroy(asdfr_msgs__msg__IdentifiedObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    asdfr_msgs__msg__IdentifiedObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
asdfr_msgs__msg__IdentifiedObject__Sequence__init(asdfr_msgs__msg__IdentifiedObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  asdfr_msgs__msg__IdentifiedObject * data = NULL;

  if (size) {
    data = (asdfr_msgs__msg__IdentifiedObject *)allocator.zero_allocate(size, sizeof(asdfr_msgs__msg__IdentifiedObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = asdfr_msgs__msg__IdentifiedObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        asdfr_msgs__msg__IdentifiedObject__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
asdfr_msgs__msg__IdentifiedObject__Sequence__fini(asdfr_msgs__msg__IdentifiedObject__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      asdfr_msgs__msg__IdentifiedObject__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

asdfr_msgs__msg__IdentifiedObject__Sequence *
asdfr_msgs__msg__IdentifiedObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  asdfr_msgs__msg__IdentifiedObject__Sequence * array = (asdfr_msgs__msg__IdentifiedObject__Sequence *)allocator.allocate(sizeof(asdfr_msgs__msg__IdentifiedObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = asdfr_msgs__msg__IdentifiedObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
asdfr_msgs__msg__IdentifiedObject__Sequence__destroy(asdfr_msgs__msg__IdentifiedObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    asdfr_msgs__msg__IdentifiedObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
asdfr_msgs__msg__IdentifiedObject__Sequence__are_equal(const asdfr_msgs__msg__IdentifiedObject__Sequence * lhs, const asdfr_msgs__msg__IdentifiedObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!asdfr_msgs__msg__IdentifiedObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
asdfr_msgs__msg__IdentifiedObject__Sequence__copy(
  const asdfr_msgs__msg__IdentifiedObject__Sequence * input,
  asdfr_msgs__msg__IdentifiedObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(asdfr_msgs__msg__IdentifiedObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    asdfr_msgs__msg__IdentifiedObject * data =
      (asdfr_msgs__msg__IdentifiedObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!asdfr_msgs__msg__IdentifiedObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          asdfr_msgs__msg__IdentifiedObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!asdfr_msgs__msg__IdentifiedObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
