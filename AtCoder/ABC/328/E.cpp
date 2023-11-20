#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll ans = 1e18;

struct DSU {
    int size;
    vector<int> parents;
    vector<int> ranks;

    DSU(int n) {
        size = n;
        parents.resize(n);
        ranks.resize(n);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int findP(int cur) {
        if (cur != parents[cur]) parents[cur] = findP(parents[cur]);
        return parents[cur];
    }

    bool join(int a, int b) {
        int pa = findP(a);
        int pb = findP(b);

        if (pa == pb) return false;
        if (ranks[pa] > ranks[pb]) parents[pb] = pa;
        else {
            if (ranks[pa] == ranks[pb]) ranks[pb]++;
            parents[pa] = pb;
        } 
        return true;
    }
};


struct Edge {
    int u, v;
    ll w;

    Edge(int uu, int vv, ll ww) {
        v = vv;
        u = uu;
        w = ww;
    }
};

void dfs(vector<Edge>& edges, DSU uf, int cur, int cnt, ll k, ll sum) {
    if (cnt == uf.size) {
        ans = min(ans, sum);
        return;
    }

    vector<int> prevP = uf.parents;
    vector<int> prevR = uf.ranks;
    for(int i = cur; i < edges.size(); i++) {
        if(uf.join(edges[i].u, edges[i].v)) {
            dfs(edges, uf, i + 1, cnt + 1, k, (sum + edges[i].w) % k);
            uf.parents = prevP;
            uf.ranks = prevR;
        }
    }
}

void task() {
    int n, m;
    ll k;

    cin >> n >> m >> k;
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        --u, --v;
        edges.emplace_back(u, v, w);
    }

    DSU uf(n);
    dfs(edges, uf, 0, 1, k, 0);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}