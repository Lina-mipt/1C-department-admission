cmake_minimum_required(VERSION 3.8)
project(1C-admission)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
SET(CMAKE_CXX_FLAGS "-O3")

add_executable(solution solv.cpp)
