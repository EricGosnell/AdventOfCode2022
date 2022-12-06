#include "../aoc2022.h"

int main() {
    stack<char> s1[9];
    s1[0].push('Q'); s1[0].push('W'); s1[0].push('P'); s1[0].push('S'); s1[0].push('Z'); s1[0].push('R'); s1[0].push('H'); s1[0].push('D');
    s1[1].push('V'); s1[1].push('B'); s1[1].push('R'); s1[1].push('W'); s1[1].push('Q'); s1[1].push('H'); s1[1].push('F');
    s1[2].push('C'); s1[2].push('V'); s1[2].push('S'); s1[2].push('H');
    s1[3].push('H'); s1[3].push('F'); s1[3].push('G');
    s1[4].push('P'); s1[4].push('G'); s1[4].push('J'); s1[4].push('B'); s1[4].push('Z');
    s1[5].push('Q'); s1[5].push('T'); s1[5].push('J'); s1[5].push('H'); s1[5].push('W'); s1[5].push('F'); s1[5].push('L');
    s1[6].push('Z'); s1[6].push('T'); s1[6].push('W'); s1[6].push('D'); s1[6].push('L'); s1[6].push('V'); s1[6].push('J'); s1[6].push('N');
    s1[7].push('D'); s1[7].push('T'); s1[7].push('Z'); s1[7].push('C'); s1[7].push('J'); s1[7].push('G'); s1[7].push('H'); s1[7].push('F');
    s1[8].push('W'); s1[8].push('P'); s1[8].push('V'); s1[8].push('M'); s1[8].push('B'); s1[8].push('H');
    stack<char> s2[9];
    for (int i = 0; i < 9; i++) {
        s2[i] = s1[i];
    }

    ifstream input("day5in.txt");
    string line;
    while (getline(input,line)) {
        if (line[0] != 'm') {
            continue;
        }
        vector<string> lineSplit = split(removeEndChar(line),' ');
        stack<char> temp;
        for (int i = 0; i < stoi(lineSplit[1]); i++) {
            s1[stoi(lineSplit[5])-1].push(s1[stoi(lineSplit[3])-1].top());
            s1[stoi(lineSplit[3])-1].pop();
            temp.push(s2[stoi(lineSplit[3])-1].top());
            s2[stoi(lineSplit[3])-1].pop();
        }
        for (int i = 0; i < stoi(lineSplit[1]); i++) {
            s2[stoi(lineSplit[5])-1].push(temp.top());
            temp.pop();
        }
    }

    cout << "Part 1: " << s1[0].top()<<s1[1].top()<<s1[2].top()<<s1[3].top()<<s1[4].top()<<s1[5].top()<<s1[6].top()<<s1[7].top()<<s1[8].top() << endl;
    cout << "Part 2: " << s2[0].top()<<s2[1].top()<<s2[2].top()<<s2[3].top()<<s2[4].top()<<s2[5].top()<<s2[6].top()<<s2[7].top()<<s2[8].top() << endl;

    return 0;
}
