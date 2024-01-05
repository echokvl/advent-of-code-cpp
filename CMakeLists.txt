cmake_minimum_required(VERSION 3.26)
project(advent_of_code_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(advent_of_code_cpp
        main.cpp

        Template.h
        run/Imports.h
        run/Runner.cpp

        2015/01/D01_2015.cpp
        2015/02/D02_2015.cpp
        2015/03/D03_2015.cpp
        2015/04/D04_2015.cpp
        2015/05/D05_2015.cpp
        2015/06/D06_2015.cpp

        2017/01/D01_2017.cpp
        2017/02/D02_2017.cpp

        2018/01/D01_2018.cpp

        2019/01/D01_2019.cpp
        2019/02/D02_2019.cpp
        2019/03/D03_2019.cpp
        2019/04/D04_2019.cpp

        2020/01/D01_2020.cpp
        2020/02/D02_2020.cpp
        2020/03/D03_2020.cpp
        2020/04/D04_2020.cpp
        2020/05/D05_2020.cpp
        2020/06/D06_2020.cpp

        2021/01/D01_2021.cpp
        2021/02/D02_2021.cpp
)
