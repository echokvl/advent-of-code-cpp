#include "D01_2018.h"

std::vector<int> D01_2018::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<int> data;
    while (std::getline(input, line)) {
        data.push_back(std::stoi(line));
    }
    return data;
}

int D01_2018::part1(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    for (const auto &value: data) {
        result += value;
    }

    return result;
}

int D01_2018::part2(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    std::unordered_map<int, bool> state;

    while (true) {
        for (const auto &value: data) {
            result += value;
            if (state[result]) {
                return result;
            }
            state[result] = true;
        }
    }
}

void D01_2018::showResults(std::string path) {
    std::cout << "Advent of Code 2018 Day 01" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}