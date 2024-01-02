#ifndef ADVENT_OF_CODE_CPP_D01_2019_H
#define ADVENT_OF_CODE_CPP_D01_2019_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

class D01_2019 {
public:
    D01_2019() = default;

    static std::vector<int> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D01_2019_H
