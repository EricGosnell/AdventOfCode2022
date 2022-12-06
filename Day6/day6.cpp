#include "../aoc2022.h"
//Part 1
//#define marker 4
//Part 2
#define marker 14


int main() {
    ifstream input("day6in.txt");
    string line;
    while(getline(input,line)) {
        vector<char> v;
        bool allDiff = true;
        int c = 0;
        for (int i = 0; i < line.size(); i++) {
            v.insert(v.begin(),line[i]);
            if (v.size() > marker) {
                v.pop_back();
            }
            for (int j = 0; j < marker; j++) {
                for (int k=j+1; k < marker; k++) {
                    if (v[j] == v[k]) {
                        allDiff = false;
                    }
                }
            }
            if (allDiff && v.size() == marker) {
                cout << "Part 2: " << c+1 << endl;
                break;
            } else {
                c++;
            }
            allDiff = true;
        }
        cout << endl;
    }
    return 0;
}
