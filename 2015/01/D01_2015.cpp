#include "D01_2015.h"

std::string D01_2015::parseInput(std::string &path) {
    std::fstream input(path);
    std::string data;
    std::getline(input, data);
    return data;
}

int D01_2015::part1(std::string &path) {
    std::string data = parseInput(path);

    int result = 0;

    for (const auto &floorInformation: data) {
        if (floorInformation == '(') {
            result++;
        }
        else {
            result--;
        }
    }

    return result;
}

int D01_2015::part2(std::string &path) {
    std::string data = parseInput(path);

    int result;

    int position = 0;
    int floor = 0;

    while (floor != -1) {
        for (const auto &floorInformation: data) {
            if (floorInformation == '(') {
                floor++;
                position++;
            }
            else {
                floor--;
                position++;
            }
            if (floor == -1) {
                result = position;
                break;
            }
        }
    }

    return result;
}

void D01_2015::showResults(std::string path) {
    std::cout << "Advent of Code 2015 Day 01" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
