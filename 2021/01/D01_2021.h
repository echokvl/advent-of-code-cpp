#ifndef ADVENT_OF_CODE_CPP_D01_2021_H
#define ADVENT_OF_CODE_CPP_D01_2021_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class D01_2021 {
public:
    D01_2021() = default;

    static std::vector<int> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D01_2021_H
