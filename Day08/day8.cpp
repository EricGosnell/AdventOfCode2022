#include "../aoc2022.h"

vector<vector<pair<int, bool>>> transpose(vector<vector<pair<int, bool>>> matrix) {
    vector<vector<pair<int, bool>>> output;
    for (int i=0; i<matrix.size(); i++) {
        output.push_back(vector<pair<int, bool>>());
        for (int j=0; j<matrix[i].size(); j++) {
            output[i].push_back(matrix[j][i]);
        }
    }
    return output;
}

vector<vector<pair<int, bool>>> reverse(vector<vector<pair<int, bool>>> matrix) {
    vector<vector<pair<int, bool>>> output;
    for (int i=0; i<matrix.size(); i++) {
        output.push_back(vector<pair<int, bool>>());
        for (int j=0; j<matrix[i].size(); j++) {
            output[i].insert(output[i].begin(), matrix[i][j]);
        }
    }
    return output;
}

int visibility(vector<vector<pair<int, bool>>>& matrix) {
    int sum = 0;
    for (int i=0; i<matrix.size(); i++) {
        int small = -1;
        for (int j=0; j<matrix[i].size(); j++) {
            if (matrix[i][j].first > small) {
                sum += matrix[i][j].second;
                matrix[i][j].second = false;
                small = matrix[i][j].first;
            }
        }
    }
    return sum;
}

int numBlocking(vector<vector<pair<int, bool>>>& matrix, int x, int y) {
    int sum = 0;
    int big = matrix[x][y].first;
    for (int i=x; i<matrix.size(); i++) {
        for (int j=y; j<matrix[i].size(); j++) {
            if (matrix[i][j].first < big) {
                sum += 1;
            } else if (matrix[i][j].first == big) {
                sum += 1;
                break;
            } else {
                break;
            }
        }
    }
    return sum;
}

long long scenic(vector<vector<pair<int, bool>>> forest, int x, int y) {
    long long sum = 1;
    sum *= numBlocking(forest, x, y);
cout << sum << endl;
    forest = reverse(forest);
    sum *= numBlocking(forest, forest.size()-x-1, y);
cout << sum << endl;
    forest = transpose(forest);
    sum *= numBlocking(forest, y, forest.size()-x-1);
cout << sum << endl;
    forest = reverse(forest);
    sum *= numBlocking(forest, y, x);
cout << sum << endl;
    return sum;
}

int main() {
    vector<vector<pair<int, bool>>> forest;
    ifstream input("day8in.txt");
    string line;
    while (getline(input, line)) {
        forest.push_back(vector<pair<int, bool>>());
        for (int i=0; i<line.size(); i++) {
            forest[forest.size()-1].push_back({line[i]-48, true});
        }
    }
    input.close();

    int sum = 0;
    sum += visibility(forest);
    forest = reverse(forest);
    sum += visibility(forest);
    forest = transpose(forest);
    sum += visibility(forest);
    forest = reverse(forest);
    sum += visibility(forest);

    for (int i=0; i<forest.size(); i++) {
        for (int j=0; j<forest[i].size(); j++) {
            if (!forest[i][j].second) {
                cout << forest[i][j].first;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Part 1: " << sum << endl;

    long long max = 0;
    int x = 0;
    int y = 0;
    for (int i=0; i<forest.size(); i++) {
        for (int j=0; j<forest[i].size(); j++) {
            int score = scenic(forest, i, j);
            if (score > max) {
                max = score;
                x = i;
                y = j;
            }
        }
        cout << x << ", " << y << ": " << forest[x][y].first << ": " << max << endl;
    }
    cout << "Part 2: " << max << endl;

    return 0;
}
