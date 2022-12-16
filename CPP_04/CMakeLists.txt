cmake_minimum_required(VERSION 3.23)
project(CPP_04)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_04

        ### -- EX00 ---
        ex00/src/main.cpp
        ex00/src/Animal.cpp
        ex00/incl/Animal.hpp
        ex00/src/Dog.cpp
        ex00/incl/Dog.hpp
        ex00/src/Cat.cpp
        ex00/incl/Cat.hpp
        ex00/src/WrongAnimal.cpp
        ex00/incl/WrongAnimal.hpp

        ### -- EX01 ---

        ex00/src/WrongCat.cpp ex00/incl/WrongCat.hpp)
