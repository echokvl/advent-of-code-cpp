#ifndef ADVENT_OF_CODE_CPP_D06_2015_H
#define ADVENT_OF_CODE_CPP_D06_2015_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Lights {
    std::string instruction;
    std::pair<int, int> from;
    std::pair<int, int> to;
};

class D06_2015 {
public:
    D06_2015() = default;

    static std::vector<Lights> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D06_2015_H
