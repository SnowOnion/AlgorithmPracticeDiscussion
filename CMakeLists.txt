cmake_minimum_required(VERSION 3.5)
project(kickstart2017)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        b-small.cpp)
add_executable(kickstart2017 ${SOURCE_FILES})