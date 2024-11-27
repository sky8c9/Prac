#include <iostream>
#include <vector>

using namespace std;

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
            ranks[i] = sizes[i] = 1;
        }
    }

    int findP(int cur) {
        if (cur != parents[cur]) parents[cur] = findP(parents[cur]);
        return parents[cur];
    }

    int getSize(int cur) {
        return sizes[findP(cur)];
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
    int n, q;
    cin >> n >> q;

    DSU uf(n);
    vector<int> cnt(n);
    vector<int> color(n);
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0; i < n; i++) {
        cnt[i] = 1;
        color[i] = i;
        l[i] = i > 0 ? i - 1 : -1;
        r[i] = i < n - 1 ? i + 1 : -1;
    }

    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, c;
            cin >> x >> c;
            --x; --c;

            x = uf.findP(x);
            int cx = color[x];
            int sz = uf.getSize(x);

            color[x] = c;
            cnt[cx] -= sz;
            cnt[c] += sz;

            if (l[x] >= 0) {
                int lx = uf.findP(l[x]);
                int rx = r[x];
                if (color[lx] == c) {
                    uf.join(lx, x);
                    x = uf.findP(x);
                    l[x] = l[lx];
                    r[x] = rx;
                    color[x] = c;
                }
            }

            if (r[x] >= 0) {
                int rx = uf.findP(r[x]);
                int lx = l[x];
                if (color[rx] == c) {
                    uf.join(rx, x);
                    x = uf.findP(x);   
                    l[x] = lx;
                    r[x] = r[rx];
                    color[x] = c;
                }
            }
        } else if (t == 2) {
            int c;
            cin >> c;
            --c;

            cout << cnt[c] << endl;
        }
    }
}

int main() {
    task();
    return 0;
}