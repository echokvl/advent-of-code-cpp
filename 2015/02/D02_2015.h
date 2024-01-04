#ifndef ADVENT_OF_CODE_CPP_D02_2015_H
#define ADVENT_OF_CODE_CPP_D02_2015_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

struct Rectangle {
    int a;
    int b;
    int c;
};

class D02_2015 {
public:
    D02_2015() = default;

    static std::vector<Rectangle> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D02_2015_H
