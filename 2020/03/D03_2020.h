#ifndef ADVENT_OF_CODE_CPP_D03_2020_H
#define ADVENT_OF_CODE_CPP_D03_2020_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class D03_2020 {
public:
    D03_2020() = default;

    static std::vector<std::string> parseInput(std::string &path);
    static int getNumberOfLines(std::vector<std::string> &data);
    static int checkForTrees(std::vector<std::string> &data,
                             std::pair<int, int> &currentPosition,
                             std::pair<int, int> &toMoveCoords,
                             int numberOfLines);
    static int part1(std::string &path);
    static int part2(std::string &path);

    static void showResults(std::string path);
};

#endif //ADVENT_OF_CODE_CPP_D03_2020_H
