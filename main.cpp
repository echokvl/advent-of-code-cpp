#include "2020/01/D01_2020.h"
#include "2020/02/D02_2020.h"
#include "2020/03/D03_2020.h"

void display2020Results() {
    D01_2020 d01_2020;
    d01_2020.showResults(R"(C:\Users\Tibor\Desktop\advent-of-code-cpp\2020\01\D01_2020.txt)");
    D02_2020 d02_2020;
    d02_2020.showResults(R"(C:\Users\Tibor\Desktop\advent-of-code-cpp\2020\02\D02_2020.txt)");
    D03_2020 d03_2020;
    d03_2020.showResults(R"(C:\Users\Tibor\Desktop\advent-of-code-cpp\2020\03\D03_2020.txt)");
}

int main() {
    std::cout << "*** Advent of Code ***" << "\n\n";

    int choice;
    std::cout << "Enter which AoC years result you want to see: (20)" << "\n";
    std::cin >> choice;
    std::cout << '\n';

    switch (choice) {
        case 20:
            display2020Results();
            break;
        default:
            std::cout << "This AoC year does not exist." << '\n';
            break;
    }

    return 0;
}
