cmake_minimum_required(VERSION 3.12)
project(adress_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(adress_book src/person.cc include/person.h src/main.cc)