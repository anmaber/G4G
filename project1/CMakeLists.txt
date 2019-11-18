project(structures)
cmake_minimum_required(VERSION 2.8)

set (CMAKE_BUILD_TYPE debug)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # enables all compiler's warning messages
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") # enables extra compiler's warning messages
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(inc/list)
add_executable(doubly_linked_list src/list.cpp)

include_directories(inc/stack)
add_executable(stack src/stack.cpp)

include_directories(inc/queue)
add_executable(queue src/queue.cpp)

include_directories(inc/priority_queue)
add_executable(priority_queue src/priorityQueue.cpp)

include_directories(inc/map)
add_executable(map src/map.cpp)
