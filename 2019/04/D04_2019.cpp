#include "D04_2019.h"

Range D04_2019::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    Range data;

    while (std::getline(input, line)) {
        char dash = line.find('-');
        data.start = std::stoi(line.substr(0, dash));
        data.end = std::stoi(line.substr(dash + 1));
    }

    return data;
}

int D04_2019::part1(std::string &path) {
    Range data = parseInput(path);

    int result = 0;

    int start = data.start;
    int end = data.end;

    for (int i = start; i < end; i++) {
        std::string current = std::to_string(i);
        bool sixDigit = false;
        bool sameAdjacentDigits = false;
        bool neverDecreases = true;
        if (current.size() == 6) { sixDigit = true; }
        for (int j = 0; j < current.size() - 1; j++) {
            if (current[j] == current[j + 1]) {
                sameAdjacentDigits = true;
            }
            if (current[j] > current[j + 1]) {
                neverDecreases = false;
                break;
            }
        }
        if (sixDigit && sameAdjacentDigits && neverDecreases) {
            result++;
        }
    }

    return result;
}

int D04_2019::part2(std::string &path) {
    Range data = parseInput(path);

    int result = 0;

    int start = data.start;
    int end = data.end;

    for (int i = start; i < end; i++) {
        std::string current = std::to_string(i);
        bool sixDigit = false;
        bool neverDecreases = true;
        bool notLargerGroupPart = false;
        if (current.size() == 6) { sixDigit = true; }
        int repeatCount = 1;
        for (int j = 0; j < current.size() - 1; j++) {
            if (current[j] == current[j + 1]) {
                repeatCount++;
            } else {
                if (repeatCount == 2) {
                    notLargerGroupPart = true;
                }
                repeatCount = 1;
            }
            if (current[j] > current[j + 1]) {
                neverDecreases = false;
                break;
            }
        }
        if (repeatCount == 2) {
            notLargerGroupPart = true;
        }
        if (sixDigit && neverDecreases && notLargerGroupPart) {
            result++;
        }
    }

    return result;
}

void D04_2019::showResults(std::string path) {
    std::cout << "Advent of Code 2019 Day 04" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}