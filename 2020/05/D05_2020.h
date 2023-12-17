#ifndef ADVENT_OF_CODE_CPP_D05_2020_H

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>

class D05_2020 {
public:
    D05_2020() = default;

    static std::vector<std::string> parseInput(std::string &path);
    static int convert(std::string &number);
    static std::vector<int> calculateSeatIds(std::vector<std::string> &data);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D05_2020_H
