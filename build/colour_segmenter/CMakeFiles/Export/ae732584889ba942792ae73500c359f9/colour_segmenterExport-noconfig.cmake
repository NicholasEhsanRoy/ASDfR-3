#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "colour_segmenter::colour_segmenter" for configuration ""
set_property(TARGET colour_segmenter::colour_segmenter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(colour_segmenter::colour_segmenter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcolour_segmenter.so"
  IMPORTED_SONAME_NOCONFIG "libcolour_segmenter.so"
  )

list(APPEND _cmake_import_check_targets colour_segmenter::colour_segmenter )
list(APPEND _cmake_import_check_files_for_colour_segmenter::colour_segmenter "${_IMPORT_PREFIX}/lib/libcolour_segmenter.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
