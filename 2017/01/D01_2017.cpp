#include "D01_2017.h"

std::string D01_2017::parseInput(std::string &path) {
    std::fstream input(path);
    std::string data;
    std::getline(input, data);
    return data;
}

int D01_2017::part1(std::string &path) {
    std::string data = parseInput(path);

    int result = 0;

    for (int i = 0; i < data.size() - 1; i++) {
        if (data[i] == data[i + 1]) {
            result += std::stoi(std::string(1, data[i]));
        }
    }

    if (data[0] == data[data.size() - 1]) {
        result += std::stoi(std::string(1, data[0]));
    }

    return result;
}

int D01_2017::part2(std::string &path) {
    std::string data = parseInput(path);

    int result = 0;

    auto n = data.size();
    auto half = n / 2;

    for (int i = 0; i < data.size(); i++) {
        if (data[i] == data[(i + half) % n]) {
            result += std::stoi(std::string(1, data[i]));
        }
    }

    return result;
}

void D01_2017::showResults(std::string path) {
    std::cout << "Advent of Code 2017 Day 01" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
