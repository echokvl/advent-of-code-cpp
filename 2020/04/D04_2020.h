#ifndef ADVENT_OF_CODE_CPP_D04_2020_H
#define ADVENT_OF_CODE_CPP_D04_2020_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <regex>
#include <fstream>

struct Passport {
    std::vector<std::unordered_map<std::string, std::string>> passportData;
};

class D04_2020 {
public:
    D04_2020() = default;

    static std::vector<Passport> parseInput(std::string &path);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};


#endif //ADVENT_OF_CODE_CPP_D04_2020_H
