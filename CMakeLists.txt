cmake_minimum_required(VERSION 3.26)
project(advent_of_code_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(advent_of_code_cpp
        main.cpp

        Template.h
        Imports.h

        2019/01/D01_2019.cpp
        2019/02/D02_2019.cpp

        2020/01/D01_2020.cpp
        2020/02/D02_2020.cpp
        2020/03/D03_2020.cpp
        2020/04/D04_2020.cpp
        2020/05/D05_2020.cpp
        2020/06/D06_2020.cpp
)
