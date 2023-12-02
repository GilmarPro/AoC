#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int getId(string s) {
    regex r("Game ([0-9]+):");
    smatch m;
    int id; 

    regex_search(s, m, r);

    return stoi(m.str(1));
}

bool ballsExceeded(string games, string ballColor, int maxBalls) {
    regex r("([0-9]+) " + ballColor);
    sregex_iterator next(games.begin(), games.end(), r);
    sregex_iterator end;
    int maxFound = 0;

    while (next != end){
        smatch match = *next;

        if (stoi(match.str(1)) > maxBalls) {
            return true;
        }

        next++;
    }

    return false;
}
        
int maxBalls(string games, string ballColor) {
    regex r("([0-9]+) " + ballColor);
    sregex_iterator next(games.begin(), games.end(), r);
    sregex_iterator end;
    int maxFound = 0;

    while (next != end){
        smatch match = *next;
        maxFound = max(maxFound, stoi(match.str(1)));
        next++;
    }

    return maxFound;
}


int main() {
    ifstream inputFile("input.txt");
    string line;
    int result = 0;

    while (getline(inputFile, line)){
        result += maxBalls(line, "red") * maxBalls(line, "green") * maxBalls(line, "blue");
    }

    cout << "Result: " << result << endl;

    return 0;
}
