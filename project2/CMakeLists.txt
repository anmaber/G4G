project(sort)
cmake_minimum_required(VERSION 2.8)

set (CMAKE_BUILD_TYPE debug)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # enables all compiler's warning messages
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") # enables extra compiler's warning messages
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(inc)
add_executable(sort src/main.cpp)
