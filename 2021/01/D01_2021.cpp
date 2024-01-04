#include "D01_2021.h"

std::vector<int> D01_2021::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<int> data;
    while (std::getline(input, line)) {
        data.push_back(std::stoi(line));
    }
    return data;
}

int D01_2021::part1(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    for (int i = 0; i < data.size() - 1; i++) {
        if (data[i] < data[i + 1]) {
            result++;
        }
    }

    return result;
}

int D01_2021::part2(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    for (int i = 3; i < data.size(); i++) {
        if (data[i] > data[i-3]) {
            result++;
        }
    }

    return result;
}

void D01_2021::showResults(std::string path) {
    std::cout << "Advent of Code 2021 Day 01" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
