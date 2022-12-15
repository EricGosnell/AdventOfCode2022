#include "../aoc2022.h"

struct Monkey {
    vector<unsigned long> items;
    vector<int> operation; // Triplet {+, *, **}
    int factor;
    Monkey* t;
    Monkey* f;
    int inspected = 0;

    Monkey(vector<unsigned long> _items, vector<int> _operation, int _factor) {
        items = _items;
        operation = _operation;
        factor = _factor;
    }
};

unsigned long calcMonkeyBusiness(vector<Monkey*> monkeys, int kFactor, int rounds) {
    for (int i=0; i<rounds; i++) {
        for (int j=0; j<monkeys.size(); j++) {
            monkeys[j]->inspected += monkeys[j]->items.size();
            for (unsigned long k : monkeys[j]->items) {
//                cout << j << ": " << k << " => ";
                if (monkeys[j]->operation[0]) {
                    k += monkeys[j]->operation[0];
                } else if (monkeys[j]->operation[1]) {
                    k *= monkeys[j]->operation[1];
                } else if (monkeys[j]->operation[2]) {
                    k *= k;
                }
                k %= 9699690; //96577; testMonkeys
//                cout << k << endl;
                if (!((k/kFactor) % monkeys[j]->factor)) {
                    monkeys[j]->t->items.push_back(k/kFactor);
                } else {
                    monkeys[j]->f->items.push_back(k/kFactor);
                }
            }
            monkeys[j]->items.clear();
        }
    }

    int x = 0;
    int y = 0;
    for (int i=0; i<monkeys.size(); i++) {
        if (monkeys[i]->inspected > x) {
            y = x;
            x = monkeys[i]->inspected;
        } else if (monkeys[i]->inspected > y) {
            y = monkeys[i]->inspected;
        }
//        cout << monkeys[i]->inspected << endl;
    }
    return (unsigned long) x*y;
}

int main() {
    vector<Monkey*> monkeys;
    Monkey* m0 = new Monkey({85,77,77},{0,7,0},19); Monkey* m1 = new Monkey({80,99},{0,11,0},3); Monkey* m2 = new Monkey({74,60,74,63,86,92,80},{8,0,0},13); Monkey* m3 = new Monkey({71,58,93,65,80,68,54,71},{7,0,0},7); Monkey* m4 = new Monkey({97,56,79,65,58},{5,0,0},5); Monkey* m5 = new Monkey({77},{4,0,0},11); Monkey* m6 = new Monkey({99,90,84,50},{0,0,1},17); Monkey* m7 = new Monkey({50,66,61,92,64,78},{3,0,0},2);
    m0->t = m6; m0->f = m7; m1->t = m3; m1->f = m5; m2->t = m0; m2->f = m6; m3->t = m2; m3->f = m4; m4->t = m2; m4->f = m0; m5->t = m4; m5->f = m3; m6->t = m7; m6->f = m1; m7->t = m5; m7->f = m1;
    monkeys.push_back(m0); monkeys.push_back(m1); monkeys.push_back(m2); monkeys.push_back(m3); monkeys.push_back(m4); monkeys.push_back(m5); monkeys.push_back(m6); monkeys.push_back(m7);

    vector<Monkey*> testMonkeys;
    Monkey* mt0 = new Monkey({79,98},{0,19,0},23); Monkey* mt1 = new Monkey({54,65,75,74},{6,0,0},19); Monkey* mt2 = new Monkey({79,60,97},{0,0,1},13); Monkey* mt3 = new Monkey({74},{3,0,0},17);
    mt0->t = mt2; mt0->f = mt3; mt1->t = mt2; mt1->f = mt0; mt2->t = mt1; mt2->f = mt3; mt3->t = mt0; mt3->f = mt1;
    testMonkeys.push_back(mt0); testMonkeys.push_back(mt1); testMonkeys.push_back(mt2); testMonkeys.push_back(mt3);

//    cout << "Part 1: " << calcMonkeyBusiness(monkeys, 3, 20) << endl;


    cout << "Part 2: " << calcMonkeyBusiness(monkeys, 1, 10000) << endl;
    return 0;
}
