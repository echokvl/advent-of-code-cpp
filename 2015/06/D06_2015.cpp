#include "D06_2015.h"

std::vector<Lights> D06_2015::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<Lights> data;

    while (std::getline(input, line)) {
        Lights lights;
        std::istringstream iss(line);
        char ignore;
        iss >> lights.instruction >> lights.from.first >> ignore >> lights.from.second >>
               ignore >> lights.to.first >> ignore >> lights.to.second;
        data.push_back(lights);
    }

    return data;
}

int D06_2015::part1(std::string &path) {
    std::vector<Lights> data = parseInput(path);

    int result = 0;

    std::vector<std::vector<int>> grid;
    for (int i = 0; i < 1000; i++) {
        std::vector<int> row;
        for (int j = 0; j < 1000; j++) {
            row.push_back(0);
        }
        grid.push_back(row);
    }

    return result;
}

int D06_2015::part2(std::string &path) {
    return 0;
}

void D06_2015::showResults(std::string path) {
    std::cout << "Advent of Code 2015 Day 06" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
