#include "D02_2015.h"

std::vector<Rectangle> D02_2015::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<Rectangle> data;

    while (std::getline(input, line)) {
        Rectangle rectangle;
        std::istringstream iss(line);
        char ignore;
        iss >> rectangle.a >> ignore >> rectangle.b >> ignore >> rectangle.c;
        data.push_back(rectangle);
    }

    return data;
}

int D02_2015::part1(std::string &path) {
    std::vector<Rectangle> data = parseInput(path);

    int result = 0;

    for (const auto &rectangle: data) {
        int a = rectangle.a;
        int b = rectangle.b;
        int c = rectangle.c;
        int wrappingPaper = 2 * ((a * b) + (b * c) + (a * c));
        int slack = std::min({a * b, b * c, a * c});
        result += wrappingPaper + slack;
    }

    return result;
}

int D02_2015::part2(std::string &path) {
    std::vector<Rectangle> data = parseInput(path);

    int result = 0;

    for (const auto &rectangle: data) {
        std::vector<int> dimensions;
        dimensions.push_back(rectangle.a);
        dimensions.push_back(rectangle.b);
        dimensions.push_back(rectangle.c);
        int a = rectangle.a, b = rectangle.b, c = rectangle.c;
        int volume = a * b * c;
        int ribbon = 2 * (a + b + c - *std::max_element(dimensions.begin(), dimensions.end()));
        result += volume + ribbon;
    }

    return result;
}

void D02_2015::showResults(std::string path) {
    std::cout << "Advent of Code 2015 Day 02" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
