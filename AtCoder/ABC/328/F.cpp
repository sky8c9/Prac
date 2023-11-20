#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> parents;
    vector<int> ranks;
    vector<ll> vals;

    DSU(int n) {
        parents.resize(n);
        ranks.resize(n);
        vals.resize(n);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
            vals[i] = 0;
        }
    }

    int findP(int cur) {
        if (cur == parents[cur]) return cur;
        int p = findP(parents[cur]);    
        vals[cur] += vals[parents[cur]];
        return parents[cur] = p;
    }

    bool join(int u, int v, ll d) {
        int pu = findP(u);
        int pv = findP(v);

        if (pu == pv) return (vals[u] - vals[v] == d);

        ll pVal = vals[u] - vals[v] - d;
        if (ranks[pv] < ranks[pu]) {
            parents[pv] = pu;
            vals[pv] = pVal;
        } else {
            if (ranks[pv] == ranks[pu]) ++ranks[pv];
            parents[pu] = pv;
            vals[pu] = -pVal;
        }

        return true;
    }
};

void task() {
    int n, q;
    cin >> n >> q;

    DSU uf(n + 1);
    vector<int> ans;
    for(int i = 1; i <= q; i++) {
        ll a, b, d;
        cin >> a >> b >> d;

        if (a == b && d != 0) continue;
        if (uf.join(a, b, d)) ans.push_back(i);
    }

    for(int& val : ans) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}