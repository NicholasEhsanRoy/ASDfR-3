# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_object_identifier_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED object_identifier_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(object_identifier_FOUND FALSE)
  elseif(NOT object_identifier_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(object_identifier_FOUND FALSE)
  endif()
  return()
endif()
set(_object_identifier_CONFIG_INCLUDED TRUE)

# output package information
if(NOT object_identifier_FIND_QUIETLY)
  message(STATUS "Found object_identifier: 0.0.0 (${object_identifier_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'object_identifier' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT object_identifier_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(object_identifier_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${object_identifier_DIR}/${_extra}")
endforeach()
