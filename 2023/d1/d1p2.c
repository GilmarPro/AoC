#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h>


int get_first_digit(std::string s) {
    for(int i = 0; i < s.size(); i++) { 
        if (isdigit(s[i])) {
            return s[i] - '0';
        }

        switch(s[i]) {
            case 'o':
                if(s.substr(i, 3) == "one") {
                    return 1;
                }
            case 't':
                if(s.substr(i, 3) == "two") {
                    return 2;
                }
                if(s.substr(i, 5) == "three") {
                    return 3;
                }
            case 'f':
                if(s.substr(i, 4) == "four") {
                    return 4;
                }
                if(s.substr(i, 4) == "five") {
                    return 5;
                }
            case 's':
                if(s.substr(i, 3) == "six") {
                    return 6;
                }
                if(s.substr(i, 5) == "seven") {
                    return 7;
                }
            case 'e':
                if(s.substr(i, 5) == "eight") {
                    return 8;
                }
            case 'n':
                if(s.substr(i, 4) == "nine") {
                    return 9;
                }
        }
    }
    return 0;
};

int get_last_digit(std::string s) {
    for(int i = s.size(); i >= 0; i--) {
        if (isdigit(s[i])) {
            return s[i] - '0';
        }

        switch(s[i]) {
            case 'e':
                if (i + 1 - 3 >= 0 && s.substr(i - 2, 3) == "one") {
                    return 1;
                }
                if (i + 1 - 5 >= 0 && s.substr(i - 4, 5) == "three") {
                    return 3;
                }
                if (i + 1 - 4 >= 0 && s.substr(i - 3, 4) == "five") {
                    return 5;
                }
                if (i + 1 - 4 >= 0 && s.substr(i - 3, 4) == "nine") {
                    return 9;
                }
            case 'o':
                if(i + 1 - 3 >= 0 && s.substr(i - 2, 3) == "two") {
                    return 2;
                }
            case 'r':
                if(i + 1 - 4 >= 0 && s.substr(i - 3, 4) == "four") {
                    return 4;
                }
            case 'x':
                if(i + 1 - 3 >= 0 && s.substr(i - 2, 3) == "six") {
                    return 6;
                }
            case 'n':
                if(i + 1 - 5 >= 0 && s.substr(i - 4, 5) == "seven") {
                    return 7;
                }
            case 't':
                if(i + 1 - 5 >= 0 && s.substr(i - 4, 5) == "eight") {
                    return 8;
                }
        }
    }
    return 0;
};

int main() {
    // Read input from file
    std::ifstream calibration_document("input.txt");
    std::string line;
    int sum, last_digit, first_digit;

    // Iterate on each line
    while (std::getline(calibration_document, line)) {
        // For each line, find first digit
        first_digit = get_first_digit(line);

        // For each line, find last digit
        last_digit = get_last_digit(line); 

        // Concatenate digits
        sum += (10 * first_digit) + last_digit;
    }

    // Return
    std::cout << "Result: " << sum << std::endl;

    return 0;
}

