#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string name;
    int score;
    Node(string name, int score) : name(name), score(score) {}
};

bool cmp (Node a, Node b) {
    if (a.score == b.score) return a.name < b.name;
    return a.score > b.score;
}

void task() {
    vector<int> points(5);
    for(int&val : points) cin >> val;

    vector<Node> v;
    for(int i = 0; i < (1 << 5); i++) {
        int score = 0;
        string name = "";

        for(int j = 0; j < 5; j++) {
            if (i >> j & 1) {
                score += points[j];
                name += (char) 'A' + j; 
            }
        }

        v.emplace_back(name, score);
    }

    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size() - 1; i++) {
        cout << v[i].name << endl;
    }
}

int main() {
    task();
    return 0;
}