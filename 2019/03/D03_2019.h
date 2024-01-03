#ifndef ADVENT_OF_CODE_CPP_D03_2019_H
#define ADVENT_OF_CODE_CPP_D03_2019_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

struct TwoWires {
    std::vector<std::string> wireOne;
    std::vector<std::string> wireTwo;
};

class D03_2019 {
public:
    D03_2019() = default;

    static TwoWires parseInput(std::string &path);

    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D03_2019_H
