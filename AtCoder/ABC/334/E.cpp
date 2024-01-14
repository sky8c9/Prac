#include <iostream>
#include <string>
#include <vector>
#include <set>

const int MOD = 998244353;
using namespace std;
using ll = long long;
struct DSU {
    vector<int> parents;
    vector<int> ranks;
    int sz = 0;

    DSU(int n) {
        sz = n;
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

        --sz;
        return true;
    }
};

ll powMod(ll x, ll y) {
    ll ans = 1;

    while(y) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }

        y >>=1;
        x *= x;
        x %= MOD;
    }

    return ans;
}

void task() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    vector<pair<int, int>> reds;
    vector<pair<int, int>> greens;
    for(int i = 0; i < h; i++) {
        cin >> grid[i];
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '.') {
                reds.emplace_back(i, j);
            } else {
                greens.emplace_back(i, j);
            }
        }
    }

    DSU uf(h * w);
    vector<int> didj{1, 0, -1, 0, 1};
    for(auto[i, j] : greens) {
        for(int k = 0; k < 4; k++) {
            int ni = i + didj[k];
            int nj = j + didj[k + 1];

            if (ni < 0 || nj < 0 || ni >= h || nj >= w || grid[ni][nj] != '#') continue;
            uf.join(i * w + j, ni * w + nj);
        }
    }

    long ans = 0;
    int gSz = uf.sz - reds.size();
    for(auto[i, j] : reds) {
        set<int> neighbor;

        for(int k = 0; k < 4; k++) {
            int ni = i + didj[k];
            int nj = j + didj[k + 1];

            if (ni < 0 || nj < 0 || ni >= h || nj >= w || grid[ni][nj] != '#') continue;
            neighbor.insert(uf.findP(ni * w + nj));        
        }

        ans += (gSz - neighbor.size() + 1) * powMod(reds.size(), MOD - 2);
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}