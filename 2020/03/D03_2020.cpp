#include "D03_2020.h"

std::vector<std::string> D03_2020::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<std::string> data;

    while (std::getline(input, line)) {
        data.push_back(line);
    }

    return data;
}

int D03_2020::getNumberOfLines(std::vector<std::string> &data) {
    return data.size();
}

int D03_2020::checkForTrees(std::vector<std::string> &data,
                           std::pair<int, int> &currentPosition,
                           std::pair<int, int> &toMoveCoords,
                           int numberOfLines) {
    int trees = 0;

    int x = currentPosition.first;
    int y = currentPosition.second;
    int xx = toMoveCoords.first;
    int yy = toMoveCoords.second;
    int rowSize = data[0].size();

    while (y < numberOfLines) {
        x += xx;
        x %= rowSize;
        y += yy;

        if (y < numberOfLines && data[y][x] == '#') {
            trees++;
        }
    }

    return trees;
}

int D03_2020::part1(std::string &path) {
    std::vector<std::string> data = parseInput(path);

    int result = 0;

    std::pair<int, int> currentPosition = {0, 0};
    std::pair<int, int> toMoveCoords = {3, 1};
    int numberOfLines = getNumberOfLines(data);

    result += checkForTrees(data, currentPosition, toMoveCoords, numberOfLines);

    return result;
}

int D03_2020::part2(std::string &path) {
    std::vector<std::string> data = parseInput(path);

    int result = 1;

    std::pair<int, int> currentPosition = {0, 0};
    std::vector<std::pair<int, int>> toMoveCoords = {
            {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}
    };
    int numberOfLines = getNumberOfLines(data);

    for (std::pair<int, int> coords: toMoveCoords) {
        result *= checkForTrees(data, currentPosition, coords, numberOfLines);
    }

    return result;
}

void D03_2020::showResults(std::string path) {
    std::cout << "Advent of Code 2020 Day 03" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}