#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h>


int main() {
    // Read input from file
    std::ifstream calibration_document("input.txt");
    std::string line;
    int sum, first_digit, last_digit;

    // Iterate on each line
    while (std::getline(calibration_document, line)) {
        // For each line, find first digit
        for (int i = 0; i < line.size(); i++) {
            if (isdigit(line[i])) {
                first_digit = line[i] - '0';
                break;
            }
        }

        // For each line, find last digit
        for (int i = line.size() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                last_digit = line[i] - '0';
                break;
            }
        }

        // Concatenate digits
        sum += (10 * first_digit) + last_digit;
    }

    // Return
    std::cout << "Result: " << sum << std::endl;

    return 0;
}
