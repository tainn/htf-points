cmake_minimum_required(VERSION 3.20)
project(HtfPoints)

set(CMAKE_CXX_STANDARD 14)
include_directories("$ENV{BZFLAG_INCLUDE_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "$ENV{BZFLAG_PLUGIN_DIR}")

add_library(HtfPoints SHARED src/HtfPoints.cpp)
set_target_properties(HtfPoints PROPERTIES PREFIX "")
