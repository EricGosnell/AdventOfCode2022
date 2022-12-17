#include "../aoc2022.h"

struct Map {
    vector<vector<int>> terr;
    pair<int, int> start, end;
    vector<vector<int>> dist;
    queue<pair<int, int>> q;
    bool part2 = true;

    Map() {
        ifstream input("day12in.txt");
        string line;
        while(getline(input, line)) {
            terr.push_back(vector<int>());
            dist.push_back(vector<int>());
            for (int i=0; i<line.length(); i++) {
                terr[terr.size()-1].push_back(int(line[i]));
                dist[dist.size()-1].push_back(0);
                if (line[i] == 'S') {
                    terr[terr.size()-1][i] = int('a');
                    start.first = terr.size()-1;
                    start.second = i;
                } else if (line[i] == 'E') {
                    terr[terr.size()-1][i] = int('z');
                    end.first = terr.size()-1;
                    end.second = i;
                }
            }
        }

        q.push(end);
        while (!q.empty()) {
            memoization(q.front().first, q.front().second);
            q.pop();
        }
    }

    void memoization(int x, int y) {
        if (terr[x][y] == int('a') && part2) {
            cout << "Part 2: " << dist[x][y] << endl;
            part2 = false;
        }
        if (x == start.first && y == start.second) {
            cout << "Part 1: " << dist[x][y] << endl;
            q = queue<pair<int, int>>();
            return;
        }
        // up
        if (x-1 >= 0 && (terr[x-1][y] == terr[x][y] || terr[x-1][y]+1 == terr[x][y] || terr[x-1][y] > terr[x][y]) && !dist[x-1][y]) {
            q.push({x-1, y});
            dist[x-1][y] = dist[x][y] + 1;
        }
        // down
        if (x+1 < terr.size() && (terr[x+1][y] == terr[x][y] || terr[x+1][y]+1 == terr[x][y] || terr[x+1][y] > terr[x][y]) && !dist[x+1][y]) {
            q.push({x+1, y});
            dist[x+1][y] = dist[x][y] + 1;
        }
        // left
        if (y-1 >= 0 && (terr[x][y-1] == terr[x][y] || terr[x][y-1]+1 == terr[x][y] || terr[x][y-1] > terr[x][y]) && !dist[x][y-1]) {
            q.push({x, y-1});
            dist[x][y-1] = dist[x][y] + 1;
        }
        // right
        if (y+1 < terr[0].size() && (terr[x][y+1] == terr[x][y] || terr[x][y+1]+1 == terr[x][y] || terr[x][y+1] > terr[x][y]) && !dist[x][y+1]) {
            q.push({x, y+1});
            dist[x][y+1] = dist[x][y] + 1;
        }
    }
};

int main() {
    Map map;

    return 0;
}
