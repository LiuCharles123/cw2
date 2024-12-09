cmake_minimum_required(VERSION 3.29)
project(CHC5028_Coursework_start_codes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CHC5028_Coursework_start_codes
        main.cpp
        Room.cpp
        Room.h
        State.cpp
        State.h
        strings.h
        wordwrap.cpp
        wordwrap.h
        GameObject.h
        GameObject.cpp
        Weapon.h
        Food.h
        Weapon.cpp
        Food.cpp
        EnemyObject.h
        EnemyObject.cpp
        Boss.h
        Boss.cpp
        Clowns.h
        Clowns.cpp)
