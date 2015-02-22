cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_subdirectory(src)

project(demo)
include_directories("include")

set(SOURCE_FILES main.cpp)
add_executable(demo ${SOURCE_FILES})
target_link_libraries(demo swears)
