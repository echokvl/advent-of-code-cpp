#include "run/Runner.h"

int main() {
    std::cout << "*** Advent of Code ***" << "\n\n";

    int choice;
    std::cout << "Enter which AoC years result you want to see: (15/17/18/19/20/21)" << "\n";
    std::cin >> choice;
    std::cout << '\n';

    Runner runner;

    switch (choice) {
        case 15:
            runner.run_2015();
            break;
        case 17:
            runner.run_2017();
            break;
        case 18:
            runner.run_2018();
            break;
        case 19:
            runner.run_2019();
            break;
        case 20:
            runner.run_2020();
            break;
        case 21:
            runner.run_2021();
            break;
        default:
            std::cout << "This AoC year does not exist or is not implemented." << '\n';
            break;
    }

    return 0;
}
