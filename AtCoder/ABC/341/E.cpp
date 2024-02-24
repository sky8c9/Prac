#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct SegTree {
    int n;
    vector<int> t;

    SegTree(int sz) {
        n = sz;
        t.resize(2 * n);
    }

    void update(int i, int val) {
        i += n;
        t[i] = val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = t[i] + t[i^1];
        }
    }

    int get(int i) {
        return t[i + n];
    }

    int query(int l, int r) {
        int ans = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans += t[l++];
            if (r&1) ans += t[--r];
        }
        return ans;
    }
};

void task() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    SegTree segtree(n - 1);
    for(int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) segtree.update(i, 1);
    }

    while(q--) {
        int k, l, r;
        cin >> k >> l >> r;
        --l; --r;

        if (k == 1) {
            if (l > 0) segtree.update(l - 1, segtree.get(l - 1) ^ 1);
            if (r < n - 1) segtree.update(r, segtree.get(r) ^ 1);
        } else {
            int ans = segtree.query(l, r);
            if (ans) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
} 

int main() {
    task();
    return 0;
}