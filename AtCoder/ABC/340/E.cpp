#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Lazy_Seg {
    int n;
    int h;
    vector<ll> val;
    vector<ll> delta;
  
    Lazy_Seg(int sz) {
        n = sz;
        h = sizeof(int) * 8 - __builtin_clz(n);

        val.resize(2 * n, 0);
        delta.resize(n, 0);
    }

    void apply(int i, ll value) {
        val[i] += value;
        if (i < n) delta[i] += value;
    }

    void build(int i) {
        while (i > 1) i >>= 1, val[i] = val[i<<1] + val[i<<1|1] + delta[i];
    }

    void push(int i) {
        for (int hh = h; hh > 0; hh--) {
            int ii = i >> hh;
            if (delta[ii] != 0) {
                apply(ii<<1, delta[ii]);
                apply(ii<<1|1, delta[ii]);
                delta[ii] = 0;
            }
        }
    }

    void update(int l, int r, ll value) {
        l += n, r += n;
        int l0 = l, r0 = r;

        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) apply(l++, value);
            if (r&1) apply(--r, value);
        }

        build(l0);
        build(r0 - 1);
    }

    ll query(int l, int r) {
        l += n, r += n;
        push(l);
        push(r - 1);

        ll res = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += val[l++];
            if (r&1) res += val[--r];
        }

        return res;
    }
};

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    Lazy_Seg segtree(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        segtree.update(i, i + 1, a[i]);
    }

    for(int i = 0; i < m; i++) {
        int index;
        cin >> index;

        ll cnt = segtree.query(index, index + 1);
        ll mul = cnt / n;
        int r = cnt % n;
        segtree.update(index, index + 1, -cnt);

        if (mul) segtree.update(0, n, mul);
        if (index + 1 < n) {
            segtree.update(index + 1, min(index + r + 1, n), 1);
        }

        if (index + r >= n) {
            segtree.update(0, ((index + r) % n) + 1, 1);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << segtree.query(i, i + 1) << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}