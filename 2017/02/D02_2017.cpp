#include "D02_2017.h"

std::vector<std::vector<int>> D02_2017::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<std::vector<int>> data;

    while (std::getline(input, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        std::string value;
        while (iss >> value) {
            row.push_back(std::stoi(value));
        }
        data.push_back(row);
    }

    return data;
}

int D02_2017::part1(std::string &path) {
    std::vector<std::vector<int>> data = parseInput(path);

    int result = 0;

    for (const auto &row: data) {
        int smallest = *std::min_element(row.begin(), row.end());
        int biggest = *std::max_element(row.begin(), row.end());
        result += biggest - smallest;
    }

    return result;
}

int D02_2017::part2(std::string &path) {
    std::vector<std::vector<int>> data = parseInput(path);

    int result = 0;

    for (const auto &row: data) {
         for (int i = 0; i < row.size(); i++) {
             for (int j = i + 1; j < row.size(); j++) {
                 if (row[i] % row[j] == 0) {
                     result += row[i] / row[j];
                 }
                 else if (row[j] % row[i] == 0) {
                     result += row[j] / row[i];
                 }
             }
         }
    }

    return result;
}

void D02_2017::showResults(std::string path) {
    std::cout << "Advent of Code 2017 Day 02" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
