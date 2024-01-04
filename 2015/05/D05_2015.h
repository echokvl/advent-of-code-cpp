#ifndef ADVENT_OF_CODE_CPP_D05_2015_H
#define ADVENT_OF_CODE_CPP_D05_2015_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class D05_2015 {
public:
    D05_2015() = default;

    static std::vector<std::string> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D05_2015_H
