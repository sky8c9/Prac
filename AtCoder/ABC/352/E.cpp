#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> parents;
    vector<int> ranks;
    int sz;

    DSU(int n) {
        parents.resize(n);
        ranks.resize(n);
        sz = n;

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

        --sz;
        return true;
    }
};

struct Edge {
    int u;
    int v;
    int w;

    Edge(int uu, int vv, int ww) {
        u = uu;
        v = vv;
        w = ww;
    }
};

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void task() {
    int n, m;
    cin >> n >> m;

    vector<map<int, int>> adjL(n);
    while(m--) {
        int k, c;
        cin >> k >> c;

        vector<int> a(k);
        for(int&val : a) cin >> val;
        for(int i = 0; i < k - 1; i++) {
            if (adjL[a[i]][a[i + 1]]) {
                adjL[a[i]][a[i + 1]] = min(adjL[a[i]][a[i + 1]], c);
            } else {
                adjL[a[i]][a[i + 1]] = c;
            }
        }
    }

    vector<Edge> edges;
    for(int u = 0; u < n; u++) {
        for(auto[v, w] : adjL[u]) {
            edges.emplace_back(u, v, w);
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU uf(n);
    ll ans = 0;
    for(int i = 0; i < edges.size(); i++) {
        if (uf.join(edges[i].u - 1, edges[i].v - 1)) {
            ans += edges[i].w;
        }

        if (uf.sz == 1) {
            cout << ans << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}