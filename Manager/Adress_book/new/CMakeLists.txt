cmake_minimum_required(VERSION 3.12)
project(AddressBook_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(new src/addressBook.cc include/addressBook.hpp)
