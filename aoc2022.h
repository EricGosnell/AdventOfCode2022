#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <array>

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

vector<string> splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
        cout << str.substr(start, end - start) << endl;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vector<string> output;
    output.push_back(str.substr(start, end - start));
    return output;
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