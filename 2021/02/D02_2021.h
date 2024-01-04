#ifndef ADVENT_OF_CODE_CPP_D02_2021_H
#define ADVENT_OF_CODE_CPP_D02_2021_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Submarine {
    std::vector<std::string> commands;
    std::vector<int> units;
};

class D02_2021 {
public:
    D02_2021() = default;

    static Submarine parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D02_2021_H
