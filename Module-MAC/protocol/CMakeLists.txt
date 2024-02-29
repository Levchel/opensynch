 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the Module-MAC
#

project(protocol)

include_directories(include)
set(SOURCE_LIB include/protocol.h  include/connection.h
               src/protocol.cpp src/connection.cpp )
add_library(protocol  STATIC ${SOURCE_LIB})

