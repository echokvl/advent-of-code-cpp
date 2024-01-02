#include "D01_2019.h"

std::vector<int> D01_2019::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<int> data;
    while (std::getline(input, line)) {
        data.push_back(std::stoi(line));
    }
    return data;
}

int D01_2019::part1(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    for (const auto &mass: data) {
        int calculation = std::ceil((mass / 3) - 2);
        result += calculation;
    }

    return result;
}

int D01_2019::part2(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    for (const auto &mass: data) {
        int currentMass = mass;
        while (true) {
            int calculation = std::ceil((currentMass / 3) - 2);
            if (calculation <= 0) break;
            result += calculation;
            currentMass = calculation;
        }
    }

    return result;
}

void D01_2019::showResults(std::string path) {
    std::cout << "Advent of Code 2019 Day 01" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
