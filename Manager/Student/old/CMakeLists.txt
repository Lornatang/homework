cmake_minimum_required(VERSION 3.12)
project(Student_Manager)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(stuMager_Easy_
        include/Student.hpp
        include/utils.hpp
        src/Student.cc)
