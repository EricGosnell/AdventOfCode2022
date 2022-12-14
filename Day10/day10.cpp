#include "../aoc2022.h"

int checkCycleCount(int cycleCount, int X) {
    if ((cycleCount - 20) % 40 == 0) {
        return (cycleCount * X);
    }
    return 0;
}

bool isLit(int cycleCount, int X) {
    if (X-1 <= (cycleCount)%40 && (cycleCount)%40 <= X+1) {
        return true;
    }
    return false;
}

int main() {
    int cycleCount = 1;
    int X = 1;
    int signalStrength = 0;
    vector<vector<bool>> screen;

    ifstream input("day10in.txt");
    string line;
    while (getline(input,line)) {
        vector<string> in = split(removeEndChar(line), ' ');
        if ((cycleCount-1)%40 == 0) {
            screen.push_back(vector<bool>());
        }
        if (in[0] == "noop") {
            screen[screen.size()-1].push_back(isLit(cycleCount, X));
            cycleCount++;
            signalStrength += checkCycleCount(cycleCount, X);
        } else if (in[0] == "addx") {
            screen[screen.size()-1].push_back(isLit(cycleCount, X));
            cycleCount++;
            signalStrength += checkCycleCount(cycleCount, X);
            X += stoi(in[1]);
            if ((cycleCount-1)%40 == 0) {
                screen.push_back(vector<bool>());
            }
            screen[screen.size()-1].push_back(isLit(cycleCount, X));
            cycleCount++;
            signalStrength += checkCycleCount(cycleCount, X);
        }
    }

    cout << "Part 1: " << signalStrength << endl;

    for (int i=0; i<screen.size(); i++) {
        for (int j=0; j<screen[i].size(); j++) {
            if (screen[i][j]) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}
