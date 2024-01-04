#include "D05_2015.h"

std::vector<std::string> D05_2015::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<std::string> data;
    while (std::getline(input, line)) {
        data.push_back(line);
    }
    return data;
}

int D05_2015::part1(std::string &path) {
    std::vector<std::string> data = parseInput(path);

    int result = 0;

    std::string vowels = "aeiou";
    std::vector<std::string> forbiddenStrings = {
        "ab", "cd", "pq", "xy"
    };

    for (const auto &line: data) {
        int vowelCount = 0;
        bool doubleLetter = false;
        bool notForbiddenStrings = false;
        for (const auto& ch : line) {
            for (const auto& vowel : vowels) {
                if (vowel == ch) {
                    vowelCount++;
                }
            }
        }
        for (const auto &string: forbiddenStrings) {
            size_t position = line.find(string);
            if (position != std::string::npos) {
                notForbiddenStrings = true;
            }
        }
        for (int i = 0; i < line.size() - 1; i++) {
            if (line[i] == line[i + 1]) {
                doubleLetter = true;
            }
        }
        if (vowelCount >= 3 && doubleLetter && !notForbiddenStrings) {
            result++;
        }
    }

    return result;
}

int D05_2015::part2(std::string &path) {
    std::vector<std::string> data = parseInput(path);

    int result = 0;

    for (const auto &line : data) {
        bool hasRepeatedPair = false;
        bool hasLetterBetween = false;
        for (int i = 0; i < line.size() - 2; i++) {
            std::string pair = line.substr(i, 2);
            if (line.find(pair, i + 2) != std::string::npos) {
                hasRepeatedPair = true;
            }
            if (i < line.size() - 2 && line[i] == line[i + 2]) {
                hasLetterBetween = true;
            }
        }
        if (hasRepeatedPair && hasLetterBetween) {
            result++;
        }
    }

    return result;
}

void D05_2015::showResults(std::string path) {
    std::cout << "Advent of Code 2015 Day 05" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}