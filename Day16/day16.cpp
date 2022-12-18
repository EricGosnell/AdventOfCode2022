#include "../aoc2022.h"

struct Valve {
    string name;
    int rate;
    bool open = false;
    vector<Valve*> tunnels;
};

int backTracker(Valve* curr, Valve* prev, int rate, int time) {
    if (!time) {
        return 0;
    }
    int best = 0;
    if (!curr->open && curr->rate) {
        curr->open = true;
        best = backTracker(curr, nullptr, rate+curr->rate, time-1);
        curr->open = false;
    }
    for (Valve* next : curr->tunnels) {
        if (next != prev) {
            int potential = backTracker(next, curr, rate, time-1);
            best = potential > best ? potential : best;
        }
    }

    return best + rate;
}

int elephantTracker(Valve* currMe, Valve* prevMe, Valve* currEl, Valve* prevEl, int rate, int time, int closed) {
    if (!closed) {
        return time * rate;
    }
    if (!time) {
        return 0;
    }
    int best = 0;
    if (!currMe->open && currMe->rate) {
        currMe->open = true;
        if (!currEl->open && currEl->rate) {
            currEl->open = true;
            best = elephantTracker(currMe, nullptr, currEl, nullptr, rate+currMe->rate+currEl->rate, time-1, closed-2);
            currEl->open = false;
        }
        for (Valve* nextEl : currEl->tunnels) {
            if (nextEl != prevEl) {
                int potentialEl = elephantTracker(currMe, nullptr, nextEl, currEl, rate+currMe->rate, time-1, closed-1);
                best = potentialEl > best ? potentialEl : best;
            }
        }
        currMe->open = false;
    }
    for (Valve* nextMe : currMe->tunnels) {
        if (nextMe != prevMe) {
            int potentialMe = 0;
            if (!currEl->open && currEl->rate) {
                currEl->open = true;
                potentialMe = elephantTracker(nextMe, currMe, currEl, nullptr, rate+currEl->rate, time-1, closed-1);
                currEl->open = false;
            }
            for (Valve* nextEl : currEl->tunnels) {
                if (nextEl != prevEl && nextEl != nextMe) {
                    int potentialEl = elephantTracker(nextMe, currMe, nextEl, currEl, rate, time-1, closed);
                    potentialMe = potentialEl > potentialMe ? potentialEl : potentialMe;
                }
            }
            best = potentialMe > best ? potentialMe : best;
        }
    }

    return best + rate;
}

int main() {
    vector<Valve*> valves;
    vector<vector<string>> tempTunnels;
    int closed = 0;

    ifstream input("day16in.txt");
    string line;
    while (getline(input, line)) {
        valves.push_back(new Valve);
        vector<string> in = split(line, ' ');
        valves[valves.size()-1]->name = in[1];
        valves[valves.size()-1]->rate = stoi(split(in[4], '=')[1]);
        if (valves[valves.size()-1]->rate) {
            closed += 1;
        }
        in.erase(in.begin(), in.begin() + 9);
        tempTunnels.push_back(vector<string>());
        for (string tunnel : in) {
            tempTunnels[tempTunnels.size()-1].push_back(tunnel);
        }
    }
    input.close();

    Valve* start;
    for (int i=0; i<tempTunnels.size(); i++) {
        for (int j=0; j<tempTunnels[i].size(); j++) {
            for (int k=0; k<valves.size(); k++) {
                if (valves[k]->name == tempTunnels[i][j] || valves[k]->name+"," == tempTunnels[i][j]) {
                    valves[i]->tunnels.push_back(valves[k]);
                    break;
                }
            }
        }
        if (valves[i]->name == "AA") {
            start = valves[i];
        }
    }

//    cout << "Part 1: " << backTracker(start, nullptr, 0, 30) << endl;
    cout << "Part 2: " << elephantTracker(start, nullptr, start, nullptr, 0, 26, closed) << endl;

    return 0;
}
