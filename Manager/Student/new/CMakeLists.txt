cmake_minimum_required(VERSION 3.12)
project(Student-Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(stuMager
        include/stuMager.h
        include/View.h
        include/Student.h
        src/Student.cc
        src/stuMager.cc
        src/main.cc
        src/View.cc)