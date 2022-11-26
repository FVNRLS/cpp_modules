cmake_minimum_required(VERSION 3.22)
project(CPP_01)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP_01

        #SRC
        # --- EX00 ---
            #ex00/main.cpp
            #ex00/Zombie.cpp
            #ex00/newZombie.cpp
            #ex00/randomChump.cpp

        # --- EX01 ---
            #ex01/main.cpp
            #ex01/Zombie.cpp
            #ex01/zombieHorde.cpp

        # --- EX02 ---
            #ex02/main.cpp

        # --- EX03 ---
            #ex03/main.cpp
            #ex03/Weapon.cpp
            #ex03/HumanA.cpp
            #ex03/HumanB.cpp

        # --- EX04 ---
            ex04/main.cpp

        # --- EX05 ---
            ex05/main.cpp

        #HEADERS
        #ex00/Zombie.hpp
        #ex01/Zombie.hpp

        #ex03/Weapon.hpp
        #ex03/HumanA.hpp
        #ex03/HumanB.hpp
        ex05/main.cpp ex05/Harl.hpp ex05/Harl.cpp)

