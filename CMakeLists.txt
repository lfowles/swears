cmake_minimum_required(VERSION 3.1)
project(swears)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

#include_directories("include")
set(SOURCE_FILES main.cpp)
add_executable(demo ${SOURCE_FILES})

target_link_libraries(demo swears)
