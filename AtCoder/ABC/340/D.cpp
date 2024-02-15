#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

void task() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adjL(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b, x;
        cin >> a >> b >> x;

        adjL[i].push_back({i + 1, a});
        adjL[i].push_back({x - 1, b});
    }

    vector<ll> dist(n, MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    while(pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for(auto[v, c] : adjL[u]) {
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << dist[n - 1] << endl;
}

int main() {
    task();
}