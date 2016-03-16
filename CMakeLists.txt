cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project("Pricing")
enable_testing()

set(CMAKE_CXX_STANDARD 14)

#library part
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(core)

add_executable(pricing main.cpp)
target_link_libraries(pricing core)