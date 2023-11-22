#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

void task() {
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    vector<int> freq(n + 1);
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;

        ++freq[a];
        q.emplace(freq[a], a);
        
        auto[f, v] = q.top();
        cout << v << endl;
    }
} 

int main() {
    task();
    return 0;
}