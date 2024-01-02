#include "D06_2020.h"

Answers D06_2020::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    Answers data;
    std::unordered_map<char, int> answer;
    int lineCount = 0;

    while (std::getline(input, line)) {
        if (line.empty()) {
            if (!answer.empty()) {
                data.characters.push_back(answer);
                data.lineCounts.push_back(lineCount);
                answer.clear();
                lineCount = 0;
            }
        }
        else {
            for (char keyValue : line) {
                answer[keyValue]++;
            }
            lineCount++;
        }
    }

    if (!data.characters.empty()) {
        data.characters.push_back(answer);
        data.lineCounts.push_back(lineCount);
    }

    return data;
}

int D06_2020::part1(std::string &path) {
    Answers data = parseInput(path);

    int result = 0;

    for (const auto &map: data.characters) {
        for (const auto &value: map) {
            if (value.second >= 1) {
                result++;
            }
        }
    }

    return result;
}

int D06_2020::part2(std::string &path) {
    Answers data = parseInput(path);

    int result = 0;

    for (std::size_t i = 0; i < data.characters.size() && i < data.lineCounts.size(); ++i) {
        const auto &map = data.characters[i];
        const auto &lineCount = data.lineCounts[i];
        for (const auto &value : map) {
            if (value.second == lineCount) {
                result++;
            }
        }
    }

    return result;
}

void D06_2020::showResults(std::string path) {
    std::cout << "Advent of Code 2020 Day 06" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}


