#include "D02_2019.h"

std::vector<int> D02_2019::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::getline(input, line);
    std::vector<int> data;
    std::istringstream iss(line);
    while (std::getline(iss, line, ',')) {
        data.push_back(std::stoi(line));
    }
    return data;
}

int D02_2019::part1(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    int ip = 0;
    data[1] = 12;
    data[2] = 2;

    while (true) {
        int opcode = data[ip];
        int i1 = data[ip + 1];
        int i2 = data[ip + 2];
        int i3 = data[ip + 3];

        if (opcode == 1) {
            data[i3] = data[i1] + data[i2];
        }
        else if (opcode == 2) {
            data[i3] = data[i1] * data[i2];
        }
        else {
            break;
        }

        ip += 4;
    }

    result += data[0];

    return result;
}

int D02_2019::part2(std::string &path) {
    std::vector<int> data = parseInput(path);

    int result = 0;

    int target = 19690720;

    for (int noun = 0; noun < 100; noun++) {
        for (int verb = 0; verb < 100; verb++) {
            std::vector<int> memory = data;
            memory[1] = noun;
            memory[2] = verb;
            for (int ip = 0; ip < memory.size(); ip += 4) {
                int opcode = memory[ip];
                int i1 = memory[ip + 1];
                int i2 = memory[ip + 2];
                int i3 = memory[ip + 3];
                if (opcode == 1) {
                    memory[i3] = memory[i1] + memory[i2];
                } else if (opcode == 2) {
                    memory[i3] = memory[i1] * memory[i2];
                } else if (opcode == 99) {
                    break;
                }
            }
            if (memory[0] == target) {
                result += (100 * noun) + verb;
                break;
            }
        }
        if (result != 0) {
            break;
        }
    }

    return result;
}

void D02_2019::showResults(std::string path) {
    std::cout << "Advent of Code 2019 Day 02" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}