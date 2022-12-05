#include "../aoc2022.h"

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

string removeEndChar(string s) {
    string s2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '\r') {
            s2 += s[i];
        }
    }
    return s2;
}

int main() {
    stack<char> s[9];
    s[0].push('Q'); s[0].push('W'); s[0].push('P'); s[0].push('S'); s[0].push('Z'); s[0].push('R'); s[0].push('H'); s[0].push('D');
    s[1].push('V'); s[1].push('B'); s[1].push('R'); s[1].push('W'); s[1].push('Q'); s[1].push('H'); s[1].push('F');
    s[2].push('C'); s[2].push('V'); s[2].push('S'); s[2].push('H');
    s[3].push('H'); s[3].push('F'); s[3].push('G');
    s[4].push('P'); s[4].push('G'); s[4].push('J'); s[4].push('B'); s[4].push('Z');
    s[5].push('Q'); s[5].push('T'); s[5].push('J'); s[5].push('H'); s[5].push('W'); s[5].push('F'); s[5].push('L');
    s[6].push('Z'); s[6].push('T'); s[6].push('W'); s[6].push('D'); s[6].push('L'); s[6].push('V'); s[6].push('J'); s[6].push('N');
    s[7].push('D'); s[7].push('T'); s[7].push('Z'); s[7].push('C'); s[7].push('J'); s[7].push('G'); s[7].push('H'); s[7].push('F');
    s[8].push('W'); s[8].push('P'); s[8].push('V'); s[8].push('M'); s[8].push('B'); s[8].push('H');

    ifstream input("day5in.txt");
    string line;
    while (getline(input,line)) {
        if (line[0] != 'm') {
            continue;
        }
        vector<string> lineSplit = split(removeEndChar(line),' ');
        for (int i = 0; i < stoi(lineSplit[1]); i++) {
            s[stoi(lineSplit[5])-1].push(s[stoi(lineSplit[3])-1].top());
            s[stoi(lineSplit[3])-1].pop();
        }
    }

    cout << "Part 1: " << s[0].top()<<s[1].top()<<s[2].top()<<s[3].top()<<s[4].top()<<s[5].top()<<s[6].top()<<s[7].top()<<s[8].top() << endl;
    return 0;
}
