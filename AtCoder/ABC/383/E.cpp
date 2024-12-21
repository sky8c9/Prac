#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> parents;
    vector<int> ranks;

    DSU(int n) {
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

    bool join(int u, int v) {
        int pu = findP(u);
        int pv = findP(v);

        if (pu == pv) return false;
        if (ranks[pu] > ranks[pv]) {
            parents[pv] = pu;
        } else {
            if (ranks[pu] == ranks[pv]) ++ranks[pv];
            parents[pu] = pv;
        }

        return true;
    }
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void task() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    vector<int> a(n + 1);
    for(int i = 0; i < k; i++) {
        int ai;
        cin >> ai;
        ++a[ai];
    }

    vector<int> b(n + 1);
    for(int i = 0; i < k; i++) {
        int bi;
        cin >> bi;
        ++b[bi];
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU uf(n + 1);
    ll ans = 0;
    for(auto[u, v, w] : edges) {
        int pu = uf.findP(u);
        int pv = uf.findP(v);
        if (pu == pv) continue;

        int cntA = a[pu] + a[pv];
        int cntB = b[pu] + b[pv];
        if (cntA && cntB) {
            int mn = min(cntA, cntB);
            ans += (ll) mn * w;
            cntA -= mn;
            cntB -= mn;
        }

        uf.join(pu, pv);
        int root = uf.findP(pu);
        a[root] = cntA;
        b[root] = cntB;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}