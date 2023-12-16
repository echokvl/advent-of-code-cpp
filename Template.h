#ifndef ADVENT_OF_CODE_CPP_TEMPLATE_H
#define ADVENT_OF_CODE_CPP_TEMPLATE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Template {
public:
    Template() = default;

    static std::string parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif
