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
            #ex02/main.cpp
            #ex02/Weapon.cpp
            #ex02/HumanA.cpp
            #ex02/HumanB.cpp

        # --- EX04 ---
            #ex04/main.cpp

        # --- EX05 ---
            #ex05/main.cpp
            #ex05/Harl.cpp

        # --- EX06 ---
            ex06/main.cpp
            ex06/Harl.cpp

        #HEADERS
            #ex00/Zombie.hpp
            #ex01/Zombie.hpp

            #ex02/Weapon.hpp
            #ex02/HumanA.hpp
            #ex02/HumanB.hpp
            #ex05/Harl.hpp
            ex06/Harl.hpp
        )

