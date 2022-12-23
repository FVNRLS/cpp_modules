cmake_minimum_required(VERSION 3.23)
project(CPP_05)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_05

        ### -- EX00 ---
#        ex00/src/main.cpp
#        ex00/src/Bureaucrat.cpp
#        ex00/incl/Bureaucrat.hpp

        ### -- EX01 ---
#        ex01/src/main.cpp
#        ex01/src/Bureaucrat.cpp
#        ex01/incl/Bureaucrat.hpp
#
#        ex01/src/AForm.cpp
#        ex01/incl/AForm.hpp

        ### -- EX02 ---
        ex02/src/main.cpp
        ex02/src/Bureaucrat.cpp
        ex02/incl/Bureaucrat.hpp

        ex02/src/AForm.cpp
        ex02/incl/AForm.hpp

        ex02/src/ShrubberyCreationForm.cpp
        ex02/incl/ShrubberyCreationForm.hpp

        ex02/src/RobotomyRequestForm.cpp
        ex02/incl/RobotomyRequestForm.hpp

        ex02/src/PresidentialPardonForm.cpp
        ex02/incl/PresidentialPardonForm.hpp
        )
