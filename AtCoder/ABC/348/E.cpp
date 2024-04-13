#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> sum;
ll total = 0;

ll findSum(int u, int p, vector<vector<int>>& adjL, vector<int>& c) {
    sum[u] = c[u];
    for(int v : adjL[u]) {
        if (v == p) continue;
        sum[u] += findSum(v, u, adjL, c);
    }
    return sum[u];
}

int findCentroid(int u, int p, vector<vector<int>>& adjL) {
    for(int v : adjL[u]) {
        if (v == p) continue;
        if (sum[v] > total / 2) return findCentroid(v, u, adjL);
    }
    return u;
}

void task() {
    int n;
    cin >> n;

    vector<vector<int>> adjL(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        total += c[i];
    }

    sum = vector<ll>(n, 0);
    findSum(0, -1, adjL, c);    
    int x = findCentroid(0, -1, adjL);

    ll ans = 0;
    queue<vector<int>> q;
    q.push({x, -1, 0});
    while(q.size()) {
        auto cur = q.front(); q.pop();
        for(int v : adjL[cur[0]]) {
            if (v == cur[1]) continue;
            ans += ll (cur[2] + 1) * c[v];
            q.push({v, cur[0], cur[2] + 1});
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}