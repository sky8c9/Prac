#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct SegTree {
    vector<int> t;
    int n;

    SegTree(int sz) {
        n = sz;
        t.resize(2*n);
    }

    void update(int i, int val) {
        i += n;
        t[i] = val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = max(t[i], t[i ^ 1]);
        }
    }

    int get(int i) {
        return t[i + n];
    }

    int query(int l , int r) {
        l += n;
        r += n;
        int ans = 0;

        for(; l < r; l >>= 1, r >>= 1) {
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

    vector<int> cpa;
    cpa.push_back(0);
    for(int i = 0; i < n; i++) {
        cpa.push_back(a[i]);
        cpa.push_back(a[i] + 1);
    }

    sort(cpa.begin(), cpa.end());
    cpa.erase(unique(cpa.begin(), cpa.end()), cpa.end());

    map<int, int> m;
    for(int i = 0; i < cpa.size(); i++) {
        m[cpa[i]] = i;
    }

    int sz = m.size();
    int len1 = 0;
    SegTree seg0(sz);
    SegTree seg1(sz);
    seg1.update(0, 1);
    for(int i = 0; i < n; i++) {
        int x = m[a[i]];
        int len0 = seg0.query(0, x);

        seg0.update(x, len0 + 1);
        seg1.update(x, max(len1 + 1, seg1.get(x)));
        if (i < n - 1) {
            len1 = seg1.query(0, m[a[i + 1]]);
            seg1.update(x + 1, max(len0 + 2, seg1.get(x + 1)));
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, seg1.get(m[a[i]]));
        ans = max(ans, seg1.get(m[a[i]] + 1));
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}