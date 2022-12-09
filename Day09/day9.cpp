#include "../aoc2022.h"
#include <map>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int _val) {
        val = _val;
    }
};

struct Tree {
    Node* root = nullptr;

    bool insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return true;
        }
        return insertRecursive(root, val);
    }

    bool insertRecursive(Node* root, int val) {
        if (val > root->val) {
            if (root->right == nullptr) {
                root->right = new Node(val);
                return true;
            } else {
                return insertRecursive(root->right, val);
            }
        } else if (val < root->val) {
            if (root->left == nullptr) {
                root->left = new Node(val);
                return true;
            } else {
                return insertRecursive(root->left, val);
            }
        } else {
            return false;
        }
    }
};

bool up(map<int, Tree>& visited, pair<int, int>& head, pair<int, int>& tail, bool coords) {
    if (head.second > tail.second) {
        tail.second += 1;
        tail.first = head.first;
    }
    head.second += 1;
    if (visited[tail.first].insert(tail.second)) {
        if (coords) {
            cout << tail.first << ", " << tail.second << endl;
        }
        return true;
    }
    return false;
}

bool down(map<int, Tree>& visited, pair<int, int>& head, pair<int, int>& tail, bool coords) {
    if (head.second < tail.second) {
        tail.second -= 1;
        tail.first = head.first;
    }
    head.second -= 1;
    if (visited[tail.first].insert(tail.second)) {
        if (coords) {
            cout << tail.first << ", " << tail.second << endl;
        }
        return true;
    }
    return false;
}

bool left(map<int, Tree>& visited, pair<int, int>& head, pair<int, int>& tail, bool coords) {
    if (head.first < tail.first) {
        tail.first -= 1;
        tail.second = head.second;
    }
    head.first -= 1;
    if (visited[tail.first].insert(tail.second)) {
        if (coords) {
            cout << tail.first << ", " << tail.second << endl;
        }
        return true;
    }
    return false;
}

bool right(map<int, Tree>& visited, pair<int, int>& head, pair<int, int>& tail, bool coords) {
    if (head.first > tail.first) {
        tail.first += 1;
        tail.second = head.second;
    }
    head.first += 1;
    if (visited[tail.first].insert(tail.second)) {
        if (coords) {
            cout << tail.first << ", " << tail.second << endl;
        }
        return true;
    }
    return false;
}

int main() {
    int sum1 = 0;
    int sum2 = 0;

    ifstream input("test.txt");
    string line;
    char dir;
    int len;

    map<int, Tree> visited1;
    map<int, Tree> visited2;
    map<int, Tree> trash;
    pair<int, int> head = {0, 0};
    pair<int, int> tail = {0, 0};
    vector<pair<int, int>> body;
    for (int i=0; i<10; i++) {
        body.push_back({0, 0});
    }
    while (getline(input,line)) {
        vector<string> in = split(removeEndChar(line),' ');
        dir = in[0][0];
        len = stoi(in[1]);
        for (int i=0; i<len; i++) {
            switch (dir) {
                case 'U':
                    sum1 += up(visited1, head, tail, false);
                    for (int i=0; i<9; i++) {
                        up(trash, body[i], body[i+1], false);
                    }
                    sum2 += up(visited2, body[8], body[9], true);
                    break;
                case 'D':
                    sum1 += down(visited1, head, tail, false);
                    for (int i=0; i<9; i++) {
                        down(trash, body[i], body[i+1], false);
                    }
                    sum2 += down(visited2, body[8], body[9], true);
                    break;
                case 'L':
                    sum1 += left(visited1, head, tail, false);
                    for (int i=0; i<9; i++) {
                        left(trash, body[i], body[i+1], false);
                    }
                    sum2 += left(visited2, body[8], body[9], true);
                    break;
                case 'R':
                    sum1 += right(visited1, head, tail, false);
                    for (int i=0; i<9; i++) {
                        right(trash, body[i], body[i+1], false);
                    }
                    sum2 += right(visited2, body[8], body[9], true);
                    break;
            }
        }
    }

    cout << "Part 1: " << sum1 << endl;
    cout << "Part 2: " << sum2 << endl;
    return 0;
}
