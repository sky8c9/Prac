#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegTree {
    vector<int> t;
    int sz;

    SegTree(int n) {
        sz = n;
        t.resize(2 * n, 0);
    }

    void update(int i, int val) {
        i += sz;
        t[i] = val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = max(t[i], t[i ^ 1]); 
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, t[l++]);
            if (r&1) ans = max(ans, t[--r]);
        }
        return ans;
    }
};

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    SegTree segtree(n);
    for(int i = 0, j = 0; i < n; i++) {
        while(j < n && 2 * a[i] > a[j]) ++j;
        segtree.update(i, j - i);
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;

        int lo = 0;
        int hi = (r - l + 1) / 2;
        while(lo < hi) {
            int k = lo + (hi - lo) / 2 + 1;            
            int mx = segtree.query(l, l + k);

            if (mx <= r - l + 1 - k) lo = k;
            else hi = k - 1;
        }

        cout << lo << endl;
    }
}

int main() {
    task();
    return 0;
}