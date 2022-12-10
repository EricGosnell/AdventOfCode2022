#include "../aoc2022.h"

void checkCycleCount(int cycleCount, int X, int& signalStrength) {
    if ((cycleCount - 20) % 40 == 0) {
        signalStrength += (cycleCount * X);
        cout << cycleCount << " " << X << " " << signalStrength << endl;
    }
}

int main() {
    int cycleCount = 0;
    int X = 1;
    int signalStrength = 0;

    ifstream input("day10in_test.txt");
    string line;
    while (getline(input,line)) {
        vector<string> in = split(removeEndChar(line), ' ');
        if (in[0] == "noop") {
            cycleCount++;
            checkCycleCount(cycleCount, X, signalStrength);
        } else if (in[0] == "addx") {
            cycleCount++;
            checkCycleCount(cycleCount, X, signalStrength);
            X += stoi(in[1]);
            cycleCount++;
            checkCycleCount(cycleCount, X, signalStrength);
        }
    }
    cout << "Part 1: " << signalStrength - 220 << endl;
    return 0;
}
