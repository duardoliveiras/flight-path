cmake_minimum_required(VERSION 3.22)
project(AEDP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(a
        main.cpp
        classes/City.cpp
        classes/City.h
        classes/Airline.cpp
        classes/Airline.h
        classes/Airport.cpp
        classes/Airport.h
        Menu.cpp
        Menu.h
        classes/Graph.h
        database/read.h
        database/read.cpp
        database/dbairport.h
        database/dbairport.cpp)