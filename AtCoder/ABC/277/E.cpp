#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void task() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> adjL(2*n + 1);
    while(m--) {
        int u,v,a;
        cin >> u >> v >> a;

        if (a == 0) {
            adjL[u + n].emplace_back(v + n, 1);
            adjL[v + n].emplace_back(u + n, 1);
        } else {
            adjL[u].emplace_back(v, 1);
            adjL[v].emplace_back(u, 1);
        }
    }

    while(k--) {
        int v; cin >> v;
        adjL[v].emplace_back(v + n, 0);
        adjL[v + n].emplace_back(v, 0);
    }

    deque<int> dq;
    vector<int> dist(2*n + 1, MAX);
    vector<bool> seen(2*n);
    dq.push_back(1);
    dist[1] = 0;
    while(dq.size()) {
        int u = dq.front(); dq.pop_front();
        if (seen[u]) continue;
        seen[u] = true;
        for(auto[v,d] : adjL[u]) {      
            if (dist[u] + d >= dist[v]) continue;
            if (d) dq.push_back(v);
            else dq.push_front(v);
            dist[v] = dist[u] + d;
        }
    }

    int mn = min(dist[n], dist[2*n]);
    int ans = mn == MAX ? -1 : mn;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}