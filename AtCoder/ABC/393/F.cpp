#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;
using ll = long long;
const int MAX = 1e6;

struct SegTree {
    vector<ll> t;
    int n;

    SegTree(int sz) {
        n = sz;
        t.resize(2*n, 0);
    }

    void update(int i, ll val) {
        i += n;
        t[i] = val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = max(t[i], t[i ^ 1]);
        }
    }

    ll query(int l , int r) {
        l += n;
        r += n;
        ll ans = 0;

        for(; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, t[l++]);
            if (r&1) ans = max(ans, t[--r]);
        }

        return ans;
    }
};

void task() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> s;
    for(int& val : a) {
        cin >> val;
        s.push_back(val);
    }

    vector<tuple<int, int, int>> p;
    for(int i = 0; i < q; i++) {
        int r, x;
        cin >> r >> x;
        p.emplace_back(r, x, i);
        s.push_back(x);
    }

    sort(p.begin(), p.end());
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    int cur = 0;
    map<int, int> m;
    for(int val : s) m[val] = ++cur;

    cur = 0;
    SegTree segtree(MAX);
    vector<int> ans(q);
    for(auto[r, x, i] : p) {
        while(cur < r) {
            int len = segtree.query(1, m[a[cur]]);
            segtree.update(m[a[cur]], len + 1);
            ++cur;
        }

        ans[i] = segtree.query(1, m[x] + 1);
    }

    for(int& val : ans) cout << val << endl;
}

int main() {
    task();
    return 0;
}