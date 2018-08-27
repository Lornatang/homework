cmake_minimum_required(VERSION 3.12)
project(shopManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(shopManager
        src/admin.cc
        include/admin.h 
	src/custom.cc 
	include/custom.h 
	src/main.cc 
	include/view.hpp 
	src/goods.cc 
	include/goods.h)
