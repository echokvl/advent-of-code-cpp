#ifndef ADVENT_OF_CODE_CPP_D02_2017_H
#define ADVENT_OF_CODE_CPP_D02_2017_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class D02_2017 {
public:
    D02_2017() = default;

    static std::vector<std::vector<int>> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D02_2017_H
