#ifndef ADVENT_OF_CODE_CPP_D04_2019_H
#define ADVENT_OF_CODE_CPP_D04_2019_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

struct Range {
    int start;
    int end;
};

class D04_2019 {
public:
    D04_2019() = default;

    static Range parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D04_2019_H
