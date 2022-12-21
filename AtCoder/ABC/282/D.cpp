#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

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

vector<vector<int>> adjL;
vector<int> color;
bool dfs(int u) {
    for(int v : adjL[u]) {
        if (color[u] == color[v]) return false;
        if (color[v] == 3) { 
            color[v] = color[u] ^ 1;
            if (!dfs(v)) return false;
        }
    }
    return true;
}

void task() {
    int n, m;
    cin >> n >> m;

    adjL.resize(n + 1);
    Dsu uf(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
        uf.join(u, v);
    }

    color.resize(n + 1, 3);
    unordered_map<int, vector<int>> comps;
    for(int i = 1; i <= n; i++) {
        comps[uf.find(i)].push_back(i);
        if (color[i] != 3) continue;
        
        color[i] = 0;
        bool isBipartile = dfs(i);
        if (!isBipartile) {
            cout << 0 << endl;
            return;
        }
    }

    ll ans = (ll) n * (n - 1) / 2 - m;
    for(auto[root, nodes] : comps) {
        int cnt_1 = 0;
        for(int node : nodes) cnt_1 += color[node];

        int cnt_0 = nodes.size() - cnt_1;
        ans -= (ll) cnt_0 * (cnt_0 - 1) / 2;
        ans -= (ll) cnt_1 * (cnt_1 - 1) / 2;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}