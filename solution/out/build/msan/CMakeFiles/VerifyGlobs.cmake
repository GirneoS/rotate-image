# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.27
cmake_policy(SET CMP0009 NEW)

# sources at CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB FOLLOW_SYMLINKS LIST_DIRECTORIES false "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/*.h")
set(OLD_GLOB
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/bmp.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/errors/read_status.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/errors/write_status.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/free_img_data.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/image.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/io.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/transformations/ccw_90.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/transformations/cw_90.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/transformations/flip_h.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/transformations/flip_v.h"
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/include/utils.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/mak/CLionProjects/assignment-3-image-transform/solution/out/build/msan/CMakeFiles/cmake.verify_globs")
endif()

# sources at CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB FOLLOW_SYMLINKS LIST_DIRECTORIES false "/Users/mak/CLionProjects/assignment-3-image-transform/solution/src/*.c")
set(OLD_GLOB
  "/Users/mak/CLionProjects/assignment-3-image-transform/solution/src/main.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/mak/CLionProjects/assignment-3-image-transform/solution/out/build/msan/CMakeFiles/cmake.verify_globs")
endif()

# sources at CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB FOLLOW_SYMLINKS LIST_DIRECTORIES false "/Users/mak/CLionProjects/assignment-3-image-transform/solution/src/*.h")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/mak/CLionProjects/assignment-3-image-transform/solution/out/build/msan/CMakeFiles/cmake.verify_globs")
endif()
