#ifndef ADVENT_OF_CODE_CPP_D02_2020_H
#define ADVENT_OF_CODE_CPP_D02_2020_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct PasswordData {
    int border1;
    int border2;
    char policy;
    std::string password;
};

class D02_2020 {
public:
    D02_2020() = default;

    static std::vector<PasswordData> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D02_2020_H
