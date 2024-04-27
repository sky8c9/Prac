#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> parents;
    vector<int> ranks;
    vector<int> sizes;

    DSU(int n) {
        parents.resize(n);
        ranks.resize(n);
        sizes.resize(n);

        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
            sizes[i] = 1;
        }
    }

    int findP(int cur) {
        if (cur != parents[cur]) parents[cur] = findP(parents[cur]);
        return parents[cur];
    }

    int findSize(int cur) {
        int p = findP(cur);
        return sizes[p];
    }

    bool join(int u, int v) {
        int pu = findP(u);
        int pv = findP(v);

        if (pu == pv) return false;
        if (ranks[pu] > ranks[pv]) {
            parents[pv] = pu;
            sizes[pu] += sizes[pv];
        } else {
            if (ranks[pu] == ranks[pv]) ++ranks[pv]; 
            parents[pu] = pv;
            sizes[pv] += sizes[pu];
        }

        return true;
    }
};

void task() {
    int n, m;
    cin >> n >> m;

    DSU uf(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        --a;--b;
        uf.join(a, b);
    }

    vector<bool> seen(n, false);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int p = uf.findP(i);
        if (seen[p]) continue;
        
        seen[p] = true;
        int sz = uf.sizes[p];
        ans += (ll) sz * (sz - 1) / 2;
    }

    cout << ans - m << endl;
}

int main() {
    task();
    return 0;
}