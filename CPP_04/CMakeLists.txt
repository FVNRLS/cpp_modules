cmake_minimum_required(VERSION 3.23)
project(CPP_04)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_04

        ### -- EX00 ---
#        ex00/src/main.cpp
#        ex00/src/Animal.cpp
#        ex00/incl/Animal.hpp
#        ex00/src/Dog.cpp
#        ex00/incl/Dog.hpp
#        ex00/src/Cat.cpp
#        ex00/incl/Cat.hpp
#        ex00/src/WrongAnimal.cpp
#        ex00/incl/WrongAnimal.hpp
#        ex00/src/WrongCat.cpp
#        ex00/incl/WrongCat.hpp

        ### -- EX01 ---
        ex01/src/main.cpp
        ex01/src/Animal.cpp
        ex01/incl/Animal.hpp
        ex01/src/Dog.cpp
        ex01/incl/Dog.hpp
        ex01/src/Cat.cpp
        ex01/incl/Cat.hpp
        ex01/src/WrongAnimal.cpp
        ex01/incl/WrongAnimal.hpp
        ex01/src/WrongCat.cpp
        ex01/incl/WrongCat.hpp

        ex01/incl/Brain.hpp ex01/src/Brain.cpp)
