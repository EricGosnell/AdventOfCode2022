#include "../aoc2022.h"

int main() {
    ifstream input("day4in.txt");
    string line;
    int sum1 = 0;
    int sum2 = 0;
    while(getline(input,line)) {
        vector<string> pair = split(line,',');
        vector<string> left = split(pair[0],'-');
        vector<string> right = split(pair[1],'-');
        int l1 = stoi(left[0]);
        int l2 = stoi(left[1]);
        int r1 = stoi(right[0]);
        int r2 = stoi(right[1]);
        if (l1 >= r1 && l2 <= r2 || l1 <= r1 && l2 >= r2) {
            sum1++;
        }
        if (l1 <= r1 && l2 >= r2 || l1 >= r1 && l1 <= r2 || l2 >= r1 && l2 <= r2) {
            sum2++;
        }
    }
    cout << "Part 1: " << sum1 << endl;
    cout << "Part 2: " << sum2 << endl;
    return 0;
}
