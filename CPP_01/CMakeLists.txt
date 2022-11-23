cmake_minimum_required(VERSION 3.22)
project(CPP_01)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_01

        #SRC
        ex00/main.cpp
        ex00/Zombie.cpp
        ex00/newZombie.cpp
        ex00/randomChump.cpp

        #HEADERS
        ex00/Zombie.hpp

        )

