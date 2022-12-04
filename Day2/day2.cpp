#include "../aoc2022.h"

int main() {
    ifstream input("day2in.txt");
    string line;

    int score1 = 0;
    int score2 = 0;
    while(getline(input, line)) {
        score1 += (line[2] - 'W') + ((line[2]-line[0]) % 21 % 3 ^ 1) * 6 % 15;
        int diff = line[0] - 64 + line[2] - 89;
        if (diff == 0) {
            score2 += 3;
        } else {
            score2 += (line[2] - 'X') * 3 + diff % 4 + diff / 4;
        }
    }
    input.close();
    cout << "Part 1: " << score1 << endl;
    cout << "Part 2: " << score2 << endl;
    return 0;
}

// Bad code no cookie
//int main() {
//    ifstream input("day2in.txt");
//    string line;
//
//    // part 1
//    int score1 = 0;
//    while(getline(input, line)) {
//        if (line[2] == 'X') {
//            score1 += 1;
//            if (line[0] == 'A') {
//                score1 += 3;
//            } else if (line[0] == 'C') {
//                score1 += 6;
//            }
//        } else if (line[2] == 'Y') {
//            score1 += 2;
//            if (line[0] == 'B') {
//                score1 += 3;
//            } else if (line[0] == 'A') {
//                score1 += 6;
//            }
//        } else if (line[2] == 'Z') {
//            score1 += 3;
//            if (line[0] == 'C') {
//                score1 += 3;
//            } else if (line[0] == 'B') {
//                score1 += 6;
//            }
//        }
//    }
//    cout << score1 << endl;
//
//    // part 2
//    ifstream sad("day2in.txt");
//    int score2 = 0;
//    while(getline(sad, line)) {
//        if (line[2] == 'X') {
//            if (line[0] == 'A') {
//                score2 += 3;
//            } else if (line[0] == 'B') {
//                score2 += 1;
//            } else if (line[0] == 'C') {
//                score2 += 2;
//            }
//        } else if (line[2] == 'Y') {
//            score2 += line[0] - 'A' + 1;
//            score2 += 3;
//        } else if (line[2] == 'Z') {
//            if (line[0] == 'A') {
//                score2 += 2;
//            } else if (line[0] == 'B') {
//                score2 += 3;
//            } else if (line[0] == 'C') {
//                score2 += 1;
//            }
//            score2 += 6;
//        }
//    }
//    cout << score2 << endl;
//
//    input.close();
//    return 0;
//}
