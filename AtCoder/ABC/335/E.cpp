#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 200001;
struct Dsu {
    vector<int> parents;
    vector<int> ranks;

    Dsu(int n) {
        parents.resize(n);
        ranks.resize(n);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int cur) {
        if (cur != parents[cur]) parents[cur] = find(parents[cur]);
        return parents[cur];
    }

    bool join(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false;
        if (ranks[pa] > ranks[pb]) parents[pb] = pa;
        else {
            if (ranks[pa] == ranks[pb]) ranks[pb]++;
            parents[pa] = pb;
        } 
        return true;
    }
};

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    vector<vector<pair<int, int>>> edges(MAX);
    vector<int> dp(n, -MAX);
    Dsu uf(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        
        if (a[u] == a[v]) uf.join(u, v);
        if (a[u] > a[v]) {
            edges[a[v]].push_back({v, u});
        } else if (a[v] > a[u]) {
            edges[a[u]].push_back({u, v});
        }
    }

    dp[uf.find(0)] = 1;
    for(int i = 0; i < MAX; i++) {
        for(auto[u, v] : edges[i]) {
            if (dp[uf.find(u)] == -MAX) continue;
            dp[uf.find(v)] = max(dp[uf.find(v)], dp[uf.find(u)] + 1);
        }
    }

    cout << max(0, dp[uf.find(n - 1)]) << endl;
}

int main() {
    task();
    return 0;
}