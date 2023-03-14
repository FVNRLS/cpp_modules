cmake_minimum_required(VERSION 3.24)
project(CPP_09)

set(CMAKE_CXX_STANDARD 98)

include_directories(./ex00/incl ./ex01/incl ./ex02/incl)

add_executable(CPP_09

#        # ex00
        ex00/src/main.cpp
        ex00/src/BitcoinExchange.cpp
        ex00/incl/BitcoinExchange.hpp

        # ex01
        ex01/src/main.cpp
        ex01/src/RPN.cpp
        ex01/incl/RPN.hpp
#
#       #ex02
#        ex02/src/main.cpp
#        ex02/src/PmergeMe.cpp
#        ex02/incl/PmergeMe.hpp
        )
