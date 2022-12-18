#include "../aoc2022.h"

#define maxY 175
#define shiftX 300
// 452-510 X, 13-173 Y

int main() {
    array<array<char,maxY>,400> map = {};
    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            map[i][j] = ' ';
        }
    }

    ifstream input("day14in.txt");
    string line;
    while (getline(input,line)) {
        size_t pos;
        while ((pos = line.find(" -> ")) != string::npos) {
            line.replace(pos, 4, ",");
        }
        pair<int,int> curr = {-1,-1};
        pair<int,int> next;
        stringstream ss(line);
        string val;
        int i = 0;
        while (getline(ss, val, ',')) {
            i++;
            if (i % 2) {
                next.first = stoi(val)-shiftX;
            } else {
                next.second = stoi(val);
                if (curr.first != -1) {
                    if (curr.first == next.first) { // Vertical Line
                        if (curr.second < next.second) {
                            for (int j=curr.second; j<=next.second; j++) {
                                map[curr.first][j] = '#';
                            }
                        } else {
                            for (int j=next.second; j<=curr.second; j++) {
                                map[curr.first][j] = '#';
                            }
                        }
                    } else { // Horizontal Line
                        if (curr.first < next.first) {
                            for (int j=curr.first; j<=next.first; j++) {
                                map[j][curr.second] = '#';
                            }
                        } else {
                            for (int j=next.first; j<=curr.first; j++) {
                                map[j][curr.second] = '#';
                            }
                        }
                    }
                }
                curr = next;
            }
        }
    }
    int count = 0;
    bool abyss = false;
    bool floor = false;
    while (!floor) {
        pair<int, int> sand = {500-shiftX, 0};
        while (true) {
            if (sand.second+1 == map[0].size() && !abyss) {
                cout << "Part 1: " << count << endl;
                abyss = true;
            }
            if (sand.second+1 == map[0].size()) {
                map[sand.first][sand.second] = '.';
                break;
            }
            if (map[sand.first][sand.second+1] == ' ') {
                sand.second += 1;
            } else if (sand.first-1 >= 0 && map[sand.first-1][sand.second+1] == ' ') {
                sand.first -= 1;
                sand.second += 1;
            } else if (sand.first+1 < map.size() && map[sand.first+1][sand.second+1] == ' ') {
                sand.first += 1;
                sand.second += 1;
            } else {
                if (sand.first == 500-shiftX && sand.second == 0) {
                    floor = true;
                }
                map[sand.first][sand.second] = '.';
                break;
            }
        }
        count += 1;
    }
    cout << "Part 2: " << count << endl;

    for (int i=0; i<map[0].size(); i++) {
        for (int j=0; j<map.size(); j++) {
            cout << map[j][i];
        }
        cout << i << endl;
    }
    return 0;
}
