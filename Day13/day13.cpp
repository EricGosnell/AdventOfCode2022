#include "../aoc2022.h"
#include <typeinfo>

int main() {
    vector<pair<queue<vector<int>>,queue<vector<int>>>> packetList;
    int sum = 0;

    // Parse input file
    ifstream input("day13in_test.txt");
    string line;
    int index = 0;
    while (getline(input, line)) {
        if (line[0] != '[') {
            index++;
            continue;
        }
        for (int i=0; i<line.size(); i++) {
            if (line[i] == '[') {

            }
        }
//        line.erase(0,1); // Remove first [
//        line.pop_back(); // Remove last \n
//        line.pop_back(); // Remove last ]
//        stringstream ss(line);
//        string value;
//        queue<vector<int>> packet;
//        while (getline(ss,value,',')) {
//            if (value[0] != '[') {
//                vector<int> item;
//                item.push_back(stoi(value));
//                packet.push_back(item);
//            }
//        }
//        cout << typeid()
//        if (!packetList[index].first) {
//            packetList[index].first = packet;
//        } else {
//            packetList[index].second = packet;
//        }
    }

    // Compare packets
    cout << "Part 1: " << sum << endl;
    return 0;
}
