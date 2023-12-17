#include "D05_2020.h"

std::vector<std::string> D05_2020::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<std::string> data;

    while (std::getline(input, line)) {
        data.push_back(line);
    }

    return data;
}

int D05_2020::convert(std::string &number) {
    int decimal = 0;
    int binarySize = number.size();

    for (int i = 0; i < binarySize; ++i) {
        if (number[i] == '1') {
            decimal += static_cast<int>(pow(2, binarySize - 1 - i));
        }
    }

    return decimal;
}

std::vector<int> D05_2020::calculateSeatIds(std::vector<std::string> &data) {
    std::vector<int> seatIds;

    for (const auto &line: data) {
        std::string row;
        std::string seat;

        for (const auto &letter: line) {
            if (letter == 'F') row += '0';
            if (letter == 'B') row += '1';
            if (letter == 'R') seat += '1';
            if (letter == 'L') seat += '0';
        }

        int rows = 0;
        int seats = 0;
        rows += convert(row);
        seats += convert(seat);

        int calculation = rows * 8 + seats;

        seatIds.push_back(calculation);
    }

    std::sort(seatIds.begin(), seatIds.end());

    return seatIds;
}

int D05_2020::part1(std::string &path) {
    std::vector<std::string> data = parseInput(path);

    int result = 0;

    std::vector<int> seatIds = calculateSeatIds(data);
    result += seatIds[seatIds.size() - 1];

    return result;
}

int D05_2020::part2(std::string &path) {
    std::vector<std::string> data = parseInput(path);

    int result = -1;

    std::vector<int> seatIds = calculateSeatIds(data);

    for (const auto &id : seatIds) {
        if (std::find(seatIds.begin(), seatIds.end(), id + 1) == seatIds.end()) {
            result = id + 1;
            break;
        }
    }

    return result;
}

void D05_2020::showResults(std::string path) {
    std::cout << "Advent of Code 2020 Day 05" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}