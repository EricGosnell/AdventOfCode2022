#include "../aoc2022.h"

#define totsMem 70000000
#define needMem 30000000

/*
 * MAX WROTE THIS BLAME HIM FOR THE VARIABLE NAMES
 * MAX WROTE THIS BLAME HIM FOR THE VARIABLE NAMES
 * MAX WROTE THIS BLAME HIM FOR THE VARIABLE NAMES
 * MAX WROTE THIS BLAME HIM FOR THE VARIABLE NAMES
 */

struct DirTree {
    string name;
    int size = 0;
    DirTree* mommy;
    vector<DirTree*> subTrees;
};

int summer(DirTree* daddy) {
    for (int i=0; i<daddy->subTrees.size(); i++) {
        daddy->size += summer(daddy->subTrees[i]);
    }
    return daddy->size;
}

int winter(DirTree* pappa) {
    int sum = pappa->size <= 100000 ? pappa->size : 0;
    for (int i=0; i<pappa->subTrees.size(); i++) {
        sum += winter(pappa->subTrees[i]);
    }
    return sum;
}

DirTree* spring(DirTree* babby, int space) {
    DirTree* debby = babby->size >= space ? babby : nullptr;
    for (int i=0; i<babby->subTrees.size(); i++) {
        DirTree* baddy = spring(babby->subTrees[i], space);
        if (debby == nullptr || (baddy != nullptr && debby->size > baddy->size && baddy->size >= space)) {
            debby = baddy;
        }
    }
    return debby;
}

int main() {
    ifstream input("day7in.txt");
    string word;

    DirTree* root = new DirTree;
    root->name = "/";

    bool cd = false;
    DirTree* curr = root;
    input >> word;
    while (input >> word) {
        if (word == "cd") {
            cd = true;
        } else if (word != "$" && word != "ls" && word != "dir") {
            if (cd && word == "..") {
                curr = curr->mommy;
            } else if (cd) {
                DirTree *dt = new DirTree;
                dt->name = word;
                curr->subTrees.push_back(dt);
                cd = false;
                dt->mommy = curr;
                curr = dt;
            } else if (isdigit(word[0])) {
                curr->size += stoi(word);
            }
        }
    }
    input.close();

    summer(root);
    cout << "Part 1: " << winter(root) << endl;
    cout << "Part 2: " << spring(root, root->size + needMem - totsMem)->size << endl;
    return 0;
}
