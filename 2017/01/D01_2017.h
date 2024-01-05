#ifndef ADVENT_OF_CODE_CPP_D01_2017_H
#define ADVENT_OF_CODE_CPP_D01_2017_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class D01_2017 {
public:
    D01_2017() = default;

    static std::string parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D01_2017_H
