#include "D04_2020.h"

std::vector<Passport> D04_2020::parseInput(std::string &path) {
    std::fstream input(path);
    std::string line;
    std::vector<Passport> data;
    Passport currentPassport;

    while (std::getline(input, line)) {
        if (line.empty()) {
            if (!currentPassport.passportData.empty()) {
                data.push_back(currentPassport);
                currentPassport.passportData.clear();
            }
        }
        else {
            std::istringstream iss(line);
            std::unordered_map<std::string, std::string> information;
            std::string keyValue;
            while (iss >> keyValue) {
                size_t position = keyValue.find(':');
                std::string key = keyValue.substr(0, position);
                std::string value = keyValue.substr(position + 1);
                information[key] = value;
            }
            currentPassport.passportData.push_back(information);
        }
    }

    if (!currentPassport.passportData.empty()) {
        data.push_back(currentPassport);
    }

    return data;
}

int D04_2020::part1(std::string &path) {
    std::vector<Passport> data = parseInput(path);

    int result = 0;

    std::vector<std::string> requiredPassportFields = {
            "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };

    for (const auto& passport : data) {
        int validPassportValues = 0;
        for (const auto& info : passport.passportData) {
            for (const auto& entry : info) {
                if (entry.first == "byr") { validPassportValues++; }
                if (entry.first == "iyr") { validPassportValues++; }
                if (entry.first == "eyr") { validPassportValues++; }
                if (entry.first == "hgt") { validPassportValues++; }
                if (entry.first == "hcl") { validPassportValues++; }
                if (entry.first == "ecl") { validPassportValues++; }
                if (entry.first == "pid") { validPassportValues++; }
            }
        }
        if (validPassportValues == 7) { result++; }
    }

    return result;
}

int D04_2020::part2(std::string &path) {
    std::vector<Passport> data = parseInput(path);

    int result = 0;

    std::regex byr_r("19[2-9][0-9]|200[0-2]");
    std::regex iyr_r("201[0-9]|2020");
    std::regex eyr_r("202[0-9]|2030");
    std::regex hgt_r("((1[5678][0-9])|(19[0-3]))cm|(59|6[0-9]|7[0-6])in");
    std::regex hcl_r("#([a-f0-9]){6}");
    std::regex ecl_r("amb|blu|brn|gry|grn|hzl|oth");
    std::regex pid_r("[0-9]{9}");

    for (const auto& passport : data) {
        int validPassportValues = 0;
        for (const auto& info : passport.passportData) {
            for (const auto& entry : info) {
                if (entry.first == "byr") {
                    if (std::regex_match(entry.second, byr_r)) {
                        validPassportValues++;
                    }
                }
                if (entry.first == "iyr") {
                    if (std::regex_match(entry.second, iyr_r)) {
                        validPassportValues++;
                    }
                }
                if (entry.first == "eyr") {
                    if (std::regex_match(entry.second, eyr_r)) {
                        validPassportValues++;
                    }
                }
                if (entry.first == "hgt") {
                    if (std::regex_match(entry.second, hgt_r)) {
                        validPassportValues++;
                    }
                }
                if (entry.first == "hcl") {
                    if (std::regex_match(entry.second, hcl_r)) {
                        validPassportValues++;
                    }
                }
                if (entry.first == "ecl") {
                    if (std::regex_match(entry.second, ecl_r)) {
                        validPassportValues++;
                    }
                }
                if (entry.first == "pid") {
                    if (std::regex_match(entry.second, pid_r)) {
                        validPassportValues++;
                    }
                }
            }
        }
        if (validPassportValues == 7) { result++; }
    }

    return result;
}

void D04_2020::showResults(std::string path) {
    std::cout << "Advent of Code 2020 Day 04" << '\n';
    std::cout << "part1: " << part1(path) << '\n';
    std::cout << "part2: " << part2(path) << '\n';
    std::cout << '\n';
}
