#include "D03_2015.h"

std::string D03_2015::parseInput(std::string &path) {
    std::fstream input(path);
    std::string data;
    std::getline(input, data);
    return data;
}

std::pair<int, int> updatePosition(std::pair<int, int> &position, char direction) {
    if (direction == '^') {
        return {position.first, position.second + 1};
    } else if (direction == '<') {
        return {position.first - 1, position.second};
    } else if (direction == '>') {
        return {position.first + 1, position.second};
    } else if (direction == 'v') {
        return {position.first, position.second - 1};
    }
    return position;
}

int D03_2015::part1(std::string &path) {
    std::string data = parseInput(path);

    int result;

    std::set<std::pair<int, int>> visited;
    visited.insert({0, 0});
    std::pair<int, int> position = {0, 0};

    for (const auto &direction: data) {
        position = updatePosition(position, direction);
        visited.insert(position);
    }

    result = visited.size();

    return result;
}

int D03_2015::part2(std::string &path) {
    std::string data = parseInput(path);

    int result;

    std::set<std::pair<int, int>> visited;
    visited.insert({0, 0});
    std::pair<int, int> santa = {0, 0};
    std::pair<int, int> roboSanta = {0, 0};

    for (int i = 0; i < data.size(); i++) {
        char direction = data[i];
        if (i % 2 == 0) {
            santa = updatePosition(santa, direction);
            visited.insert(santa);
        }
        else {
            roboSanta = updatePosition(roboSanta, direction);
            visited.insert(roboSanta);
        }
    }

    result = visited.size();

    return result;
}

void D03_2015::showResults(std::string path) {
    std::cout << "Advent of Code 2015 Day 03" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}

