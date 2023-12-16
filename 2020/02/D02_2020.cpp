#include "D02_2020.h"

std::vector<PasswordData> D02_2020::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<PasswordData> data;

    while (std::getline(input, line)) {
        PasswordData passwordData;
        std::istringstream iss(line);
        char ignore;
        iss >> passwordData.border1 >> ignore >> passwordData.border2
            >> passwordData.policy >> ignore >> passwordData.password;
        data.push_back(passwordData);
    }

    return data;
}

int D02_2020::part1(std::string &path) {
    std::vector<PasswordData> data = parseInput(path);

    int result = 0;

    for (const auto& password: data) {
        int policyAppearanceCount = 0;
        for (const auto& letter: password.password) {
            if (letter == password.policy) {
                policyAppearanceCount++;
            }
        }
        if (policyAppearanceCount >= password.border1 &&
            policyAppearanceCount <= password.border2) {
            result++;
        }
    }

    return result;
}

int D02_2020::part2(std::string &path) {
    std::vector<PasswordData> data = parseInput(path);

    int result = 0;

    for (const auto& password: data) {
        int index1 = password.border1 - 1;
        int index2 = password.border2 - 1;
        if ((password.password[index1] == password.policy)
            != (password.password[index2] == password.policy)) {
            result++;
        }
    }

    return result;
}

void D02_2020::showResults(std::string path) {
    std::cout << "Advent of Code 2020 Day 02" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
