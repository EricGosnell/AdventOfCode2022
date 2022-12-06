#include "../aoc2022.h"

int main() {
    ifstream input("day6in_test.txt");
    string line;
    while(getline(input,line)) {
        vector<char> v;
        bool allDiff = true;
        int c = 0;
        for (int i = 0; i < line.size(); i++) {
            v.insert(v.begin(),line[i]);
            if (v.size() > 4) {
                v.pop_back();
            }
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (v[j] == v[k]) {
                        allDiff = false;
                    }
                }
            }
            if (allDiff) {
                cout << "Part 1: " << c << endl;
            } else {
                cout << line[c] << " ";
                c++;
            }
            allDiff = true;
        }
        cout << endl;
    }
    return 0;
}
