#include "D03_2019.h"

TwoWires D03_2019::parseInput(std::string &path) {
    std::ifstream input(path);
    std::string line;
    bool secondLine = false;
    TwoWires data;

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string value;
        while (std::getline(iss, value, ',')) {
            if (!secondLine) {
                data.wireOne.push_back(value);
            } else {
                data.wireTwo.push_back(value);
            }
        }
        secondLine = true;
    }

    return data;
}

std::vector<std::pair<int, int>> makeWireCalculation(std::string direction, int distance,
                                                               std::pair<int, int> &startingPos) {
    std::vector<std::pair<int, int>> wireCoords;
    for (int j = 0; j < distance; j++) {
        if (direction == "R") { startingPos.first++; }
        else if (direction == "L") { startingPos.first--; }
        else if (direction == "U") { startingPos.second++; }
        else { startingPos.second--; }
        wireCoords.push_back(startingPos);
    }

    return wireCoords;
}

std::vector<std::pair<int, int>> calculateWireCoords(std::vector<std::string> &wire) {
    std::vector<std::pair<int, int>> coordinates;
    std::pair<int, int> startingPoint = {0, 0};

    for (const auto &instruction: wire) {
        std::string direction = instruction.substr(0, 1);
        int distance = std::stoi(instruction.substr(1));
        std::vector<std::pair<int, int>> coords =
            makeWireCalculation(direction, distance, startingPoint);
        coordinates.insert(coordinates.end(), coords.begin(), coords.end());
    }

    return coordinates;
}

std::map<std::pair<int, int>, bool> calculateWireTwoCoords(std::vector<std::string> &wire) {
    std::map<std::pair<int, int>, bool> coordinates;
    std::pair<int, int> startingPoint = {0, 0};

    for (const auto &instruction: wire) {
        std::string direction = instruction.substr(0, 1);
        int distance = std::stoi(instruction.substr(1));
        std::vector<std::pair<int, int>> coords = makeWireCalculation(direction, distance, startingPoint);
        for (const auto &entry: coords) {
            coordinates[entry] = false;
        }
    }

    return coordinates;
}

int D03_2019::part1(std::string &path) {
    TwoWires data = parseInput(path);

    int result = INT_MAX;

    std::vector<std::pair<int, int>> intersections;

    std::vector<std::string> wireOne = data.wireOne;
    std::vector<std::string> wireTwo = data.wireTwo;

    std::vector<std::pair<int, int>> wireOneCoords = calculateWireCoords(wireOne);
    std::map<std::pair<int, int>, bool> wireTwoCoords = calculateWireTwoCoords(wireTwo);

    for (const auto &step : wireOneCoords) {
        if (wireTwoCoords.find(step) != wireTwoCoords.end()) {
            intersections.push_back({step.first, step.second});
        }
    }

    for (const auto &intersection: intersections) {
        int manhattanDistance = abs(intersection.first) + abs(intersection.second);
        result = std::min(result, manhattanDistance);
    }

    return result;
}

int D03_2019::part2(std::string &path) {
    TwoWires data = parseInput(path);

    int result = 0;

    return result;
}

void D03_2019::showResults(std::string path) {
    std::cout << "Advent of Code 2019 Day 03" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
