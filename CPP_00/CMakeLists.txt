cmake_minimum_required(VERSION 3.22)
project(CPP_00)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPP_00

        #SRC
        ex01/main.cpp
        ex01/PhoneBook.cpp
        ex01/Contacts.cpp

        #HEADERS
        ex01/PhoneBook.hpp
        ex01/Contacts.hpp
        )
