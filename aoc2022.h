#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

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