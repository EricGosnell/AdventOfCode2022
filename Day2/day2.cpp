#include "../aoc2022.h"

int main() {
    ifstream input("day2In.txt");
    string line;

    // part 1
    int score1 = 0;
    while(getline(input, line)) {
        if (line[2] == 'X') {
            score1 += 1;
            if (line[0] == 'A') {
                score1 += 3;
            } else if (line[0] == 'C') {
                score1 += 6;
            }
        } else if (line[2] == 'Y') {
            score1 += 2;
            if (line[0] == 'B') {
                score1 += 3;
            } else if (line[0] == 'A') {
                score1 += 6;
            }
        } else if (line[2] == 'Z') {
            score1 += 3;
            if (line[0] == 'C') {
                score1 += 3;
            } else if (line[0] == 'B') {
                score1 += 6;
            }
        }
    }
    cout << score1 << endl;

    // part 2
    ifstream sad("day2In.txt");
    int score2 = 0;
    while(getline(sad, line)) {
        if (line[2] == 'X') {
            if (line[0] == 'A') {
                score2 += 3;
            } else if (line[0] == 'B') {
                score2 += 1;
            } else if (line[0] == 'C') {
                score2 += 2;
            }
        } else if (line[2] == 'Y') {
            score2 += line[0] - 'A' + 1;
            score2 += 3;
        } else if (line[2] == 'Z') {
            if (line[0] == 'A') {
                score2 += 2;
            } else if (line[0] == 'B') {
                score2 += 3;
            } else if (line[0] == 'C') {
                score2 += 1;
            }
            score2 += 6;
        }
    }
    cout << score2 << endl;

    input.close();
    return 0;
}
