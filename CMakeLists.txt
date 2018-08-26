cmake_minimum_required(VERSION 3.10)
project(utils C)

set(CMAKE_C_STANDARD 11)

include_directories(reSize)

add_executable(utils reSize/resize.c)
