#include "D01_2020.h"

std::vector<int> D01_2020::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<int> data;

    while (std::getline(input, line)) {
        data.push_back(std::stoi(line));
    }

    return data;
}

int D01_2020::part1(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    int target = 2020;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] + data[j] == target) {
                int number1 = data[i];
                int number2 = data[j];
                result += number1 * number2;
            }
        }
    }

    return result;
}

int D01_2020::part2(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    int target = 2020;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            for (int k = j + 1; k < data.size(); k++) {
                if (data[i] + data[j] + data[k] == target) {
                    int number1 = data[i];
                    int number2 = data[j];
                    int number3 = data[k];
                    result += number1 * number2 * number3;
                }
            }
        }
    }

    return result;
}

void D01_2020::showResults(std::string path) {
    std::cout << "Advent of Code 2020 Day 01" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
