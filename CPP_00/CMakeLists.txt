cmake_minimum_required(VERSION 3.22)
project(CPP_00)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_00

        #SRC
        #ex00/megaphone.cpp
        ex01/main.cpp
        ex01/Contacts.cpp
        ex01/PhoneBook.cpp
        #ex02/tests.cpp
        #ex02/Account.cpp

        #HEADERS
        ex01/Contacts.hpp
        ex01/PhoneBook.hpp
        #ex02/Account.hpp
        )
