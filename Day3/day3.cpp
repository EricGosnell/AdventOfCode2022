#include "../aoc2022.h"
#include <bitset>

int main() {
    int sum1 = 0;
    int sum2 = 0;
    ifstream input("day3in.txt");
    string line;
    bitset<52> copies;
    bitset<52> group1;
    bitset<52> group2;
    while (getline(input, line)) {
        // part 1
        for (int i=0; i<line.length()/2; i++) {
            if (line[i] >= 'a') {
                copies.set(line[i] - 'a');
            } else {
                copies.set(line[i] - 'A' + 26);
            }
        }
        for (int i=line.length()/2; i<line.length(); i++) {
            if (line[i] >= 'a' && copies[line[i] - 'a']) {
                sum1 += line[i] - 'a' + 1;
                break;
            } else if (line[i] < 'a' && copies[line[i] - 'A' + 26]) {
                sum1 += line[i] - 'A' + 26 + 1;
                break;
            }
        }
        copies.reset();

        // part 2
        if (group1.none()) {
            for (int i=0; i<line.length(); i++) {
                if (line[i] >= 'a') {
                    group1.set(line[i] - 'a');
                } else {
                    group1.set(line[i] - 'A' + 26);
                }
            }
        } else if (group2.none()) {
            for (int i=0; i<line.length(); i++) {
                if (line[i] >= 'a' && group1[line[i] - 'a']) {
                    group2.set(line[i] - 'a');
                } else if (line[i] < 'a' && group1[line[i] - 'A' + 26]) {
                    group2.set(line[i] - 'A' + 26);
                }
            }
        } else {
            for (int i=0; i<line.length(); i++) {
                if (line[i] >= 'a' && group2[line[i] - 'a']) {
                    sum2 += line[i] - 'a' + 1;
                    break;
                } else if (line[i] < 'a' && group2[line[i] - 'A' + 26]) {
                    sum2 += line[i] - 'A' + 26 + 1;
                    break;
                }
            }
            group1.reset();
            group2.reset();
        }
    }

    cout << "Part 1: " << sum1 << endl;
    cout << "Part 2: " << sum2 << endl;

    return 0;
}
