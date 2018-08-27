cmake_minimum_required(VERSION 3.12)
project(Student-Manager)

set(CMAKE_CXX_STANDARD 17)


add_executable(Student-Manager
        include/stuMager.h
        include/view.h
        include/student.h
        lib/student.cc
        lib/stuMager.cc
        src/main.cc
        lib/view.cc)

add_library(stumager SHARED lib/student.cc lib/stuMager.cc lib/view.cc )


install(TARGETS Student-Manager stumager
        RUNTIME DESTINATION ~/Desktop/bin
        LIBRARY DESTINATION ~/Desktop/lib)

