cmake_minimum_required(VERSION 3.12)
project(studentManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(studentManager/include)

add_executable(
        studentManager/include/info.h
        studentManager/info.cc)