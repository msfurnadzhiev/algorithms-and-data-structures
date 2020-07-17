cmake_minimum_required(VERSION 3.16)
project(Deque)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

add_executable(Deque main.cpp Deque.h Deque.cpp Tests/DequeTest.cpp)
target_link_libraries(Deque gtest gtest_main)