#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

void task() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for(ll&val : a) cin >> val;

    vector<vector<pair<int, int>>> adjL(n);
    for(int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;

        --u; --v;
        adjL[u].emplace_back(v, b);
        adjL[v].emplace_back(u, b);
    }

    vector<ll> d(n, MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({a[0], 0});
    while(pq.size()) {
        auto [c, u] = pq.top(); pq.pop();
        if (c > d[u]) continue;

        for(auto [v, b] : adjL[u]) {
            if (a[v] + c + b < d[v]) {
                d[v] = a[v] + c + b;
                pq.push({d[v], v});
            }
        }
    }

    for(int i = 1; i < n; i++) {
        cout << d[i] << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}