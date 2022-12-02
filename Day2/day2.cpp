#include "../aoc2022.h"

int main() {
    ifstream input("day1In.txt");
    string line;
    int score = 0;
    while(getline(input, line)) {
        if (line[2] == 'X') {
            score += 1;
        } else if (line[2] == 'Y') {
            score += 2;
        } else if (line[2] == 'Z') {
            score += 3;
        }
    }

    return 0;
}
