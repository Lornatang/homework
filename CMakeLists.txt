cmake_minimum_required(VERSION 3.10)
project(webbench)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(
        socket.c webbench.c)
