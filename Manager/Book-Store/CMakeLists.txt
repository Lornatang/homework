cmake_minimum_required(VERSION 3.12)
project(Book_Store_Management_System)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(books SHARED
        lib/admin.cc
        lib/customer.cc
        lib/library.cc
        lib/log.cc
        lib/password.cc
        lib/staff.cc
        lib/user.cc)

add_library(book STATIC src/main.cc)


add_executable(bookStore
        include/Admin.h
        include/Book.h
        include/Customer.h
        include/Library.h
        include/Log.h
        include/Password.h
        include/Staff.h
        include/User.h
        lib/admin.cc
        lib/customer.cc
        lib/library.cc
        lib/log.cc
        lib/password.cc
        lib/staff.cc
        lib/user.cc
        src/main.cc)


install(TARGETS bookStore book books
        RUNTIME DESTINATION ~/Desktop
        ARCHIVE DESTINATION ~/Desktop/bookStore/lib
        LIBRARY DESTINATION ~/Desktop/bookStore/lib)