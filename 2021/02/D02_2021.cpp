#include "D02_2021.h"

Submarine D02_2021::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    Submarine data;

    while (std::getline(input, line)) {
        char space = line.find(' ');
        std::string command = line.substr(0, space);
        int unit = std::stoi(line.substr(space + 1));
        data.commands.push_back(command);
        data.units.push_back(unit);
    }

    return data;
}

int D02_2021::part1(std::string &path) {
    Submarine data = parseInput(path);

    int result = 0;

    int horizontalPosition = 0;
    int depth = 0;

    for (int i = 0; i < data.commands.size(); i++) {
        if (data.commands[i] == "forward") {
            horizontalPosition += data.units[i];
        }
        else if (data.commands[i] == "up") {
            depth -= data.units[i];
        }
        else {
            depth += data.units[i];
        }
    }

    result += horizontalPosition * depth;

    return result;
}

int D02_2021::part2(std::string &path) {
    Submarine data = parseInput(path);

    int result = 0;

    int horizontalPosition = 0;
    int depth = 0;
    int aim = 0;

    for (int i = 0; i < data.commands.size(); i++) {
        if (data.commands[i] == "forward") {
            horizontalPosition += data.units[i];
            depth += aim * data.units[i];
        }
        else if (data.commands[i] == "up") {
            aim -= data.units[i];
        }
        else {
            aim += data.units[i];
        }
    }

    result += horizontalPosition * depth;

    return result;
}

void D02_2021::showResults(std::string path) {
    std::cout << "Advent of Code 2021 Day 02" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}