#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool validateInput(int argc, char** argv) {
    if (argc == 0) {
        cout << "You must enter the input filename as parameter" << endl;
        return false;
    } 

    return true;
}

int sumValidNumbers(string t, string m, string b) {
    int sum=0, pos, len, lenParsed=0;
    string row, number, portionAbove, portionBelow, portionLeft, portionRight;
    regex rDig("([0-9]+)");
    regex rSym("([-!$%^&*()_+|~=`{}\\:;'<>?,/@#])");
    smatch numberMatch, symbolMatch;

    // Find next number in the row
    row = m;

    while (regex_search(row, numberMatch, rDig)) {
        number = numberMatch.str();
        // Get its position and size
        pos = numberMatch.position() + lenParsed;
        len = numberMatch.length();
        // Retrieve portions around number
        if (t != "") {
            portionAbove = t.substr(pos == 0 ? 0 : pos - 1, len + 2);

            if (regex_search(portionAbove, symbolMatch, rSym)) {
                sum += stoi(number);
                lenParsed += numberMatch.prefix().str().size() + numberMatch.str().size();
                row = numberMatch.suffix();
                continue;
            }
        }

        // portionLeft = pos ? m[pos - 1] : "";
        if (pos) {
            portionLeft = m[pos - 1];
        } else {
            portionLeft = "";
        }

        // portionRight = pos + len < m.size() ? m[pos + len] : "";
        if (pos + len < m.size()) {
            portionRight = m[pos + len];
        } else {
            portionRight = "";
        }
        
        if (regex_search(portionLeft, symbolMatch, rSym) || regex_search(portionRight, symbolMatch, rSym)) {
            sum += stoi(number);
            lenParsed += numberMatch.prefix().str().size() + numberMatch.str().size();
            row = numberMatch.suffix();
            continue;
        }

        if (b != "") {
            portionBelow = b.substr(pos == 0 ? 0 : pos - 1, len + 2);

            if (regex_search(portionBelow, symbolMatch, rSym)) {
                sum += stoi(number);
            }
        }

        lenParsed += numberMatch.prefix().str().size() + numberMatch.str().size();
        row = numberMatch.suffix();
    }
       
    // Return the sum
    return sum;
}


int main(int argc, char** argv) {
    if (!validateInput(argc, argv)) {
        return 1;
    }

    ifstream inputFile(argv[1]);
    string topRow, midRow, botRow, newRow; 
    int result=0;

    getline(inputFile, midRow);
    getline(inputFile, botRow);

    result += sumValidNumbers("", midRow, botRow);

    while (getline(inputFile, newRow)) {
        topRow = midRow;
        midRow = botRow;
        botRow = newRow;
        result += sumValidNumbers(topRow, midRow, botRow);
    }

    topRow = midRow;
    midRow = botRow;

    result += sumValidNumbers(topRow, midRow, "");

    cout << result << endl;

    return 0;
}
