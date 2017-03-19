cmake_minimum_required (VERSION 2.6)
project (TokyoTower)

# The version number.
set (TT_VERSION_MAJOR 0)
set (TT_VERSION_MINOR 1)
set (TT_VERSION_PATCH 1)

# Configuration file to pass settings to project source code.
configure_file (
  "${PROJECT_SOURCE_DIR}/BuildConfig.h.in"
  "${PROJECT_BINARY_DIR}/BuildConfig.h"
  )

# Set compiler-specific flags
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  add_definitions(-std=c++14)
  set(warnings "-Wall -Wextra -Werror")
endif()

# Add the binary tree to the search path for include files
# so that we will find the build config file.
include_directories("${PROJECT_BINARY_DIR}")

# Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.63.0 COMPONENTS program_options REQUIRED) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(TokyoTower TokyoTower.cpp)
    target_link_libraries(TokyoTower ${Boost_LIBRARIES})
endif()