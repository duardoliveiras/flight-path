cmake_minimum_required(VERSION 3.22)
project(AEDP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(AEDP2
        main.cpp
        City.cpp
        City.h
        Airline.cpp
        Airline.h
        Airport.cpp
        Airport.h
        Menu.cpp
        Menu.h
        Graph.h
        read.h
        read.cpp)