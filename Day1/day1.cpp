#include "../aoc2022.h"

int main() {
    priority_queue<int> q;
    int curr = 0;

    ifstream input("day1In.txt");
    string line;
    while(getline(input, line)) {
        if (line.empty()) {
            q.push(curr);
            curr = 0;
        } else {
            curr += stoi(line);
        }
    }

    cout << "Part 1: " << q.top() << endl;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += q.top();
        q.pop();
    }
    cout << "Part 2: " << sum << endl;
    input.close();
    return 0;
}

//Bad code no cookie
//int mainX() {
//    ifstream input("day1In.txt");
//
//    string line;
//    int max[3];
//    int curr = 0;
//    while(getline(input, line)) {
//        if (line.empty()) {
//            if (curr > max[0]) {
//                max[2] = max[1];
//                max[1] = max[0];
//                max[0] = curr;
//            } else if (curr > max[1]) {
//                max[2] = max[1];
//                max[1] = curr;
//            } else if (curr > max[2]) {
//                max[2] = curr;
//            }
//            curr = 0;
//        } else {
//            curr += stoi(line);
//        }
//    }
//
//    cout << max[0]+max[1]+max[2] << endl;
//
//    return 0;
//}