#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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

void task() {
    int n, m;
    cin >> n >> m;

    DSU uf(n + 1);
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (!uf.join(u, v)) edges.emplace_back(u, i + 1);
    }

    set<int> gid;
    for(int i = 1; i <= n; i++) gid.insert(uf.findP(i));

    int cnt = gid.size() - 1;
    cout << cnt << endl;

    for(int i = 0; i < cnt; i++) {
        auto[u, num] = edges[i];

        for(int v : gid) {
            int pu = uf.findP(u);
            int pv = uf.findP(v);

            if (pu != pv) {
                uf.join(pu, pv);
                gid.erase(pu);
                gid.erase(pv);

                int root = uf.findP(pu);
                gid.insert(root);
                cout << num << " " << u << " " << v << endl;
                break;
            }
        }
    }
}

int main() {
    task();
    return 0;
}