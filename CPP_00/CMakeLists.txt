cmake_minimum_required(VERSION 3.22)
project(CPP_00)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_00

        #SRC
        ex02/tests.cpp
        ex02/Account.cpp

        #HEADERS
        ex02/Account.hpp)

