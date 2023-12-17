#ifndef ADVENT_OF_CODE_CPP_D06_2020_H
#define ADVENT_OF_CODE_CPP_D06_2020_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>

struct Answers {
    std::vector<std::unordered_map<char, int>> answers;
};

class D06_2020 {
public:
    D06_2020() = default;

    static std::vector<Answers> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D06_2020_H