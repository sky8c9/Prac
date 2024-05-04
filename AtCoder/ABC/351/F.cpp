#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

struct SegTree {
    vector<ll> t;
    int n;

    SegTree(int sz) {
        n = sz;
        t.resize(2*n);
    }

    void add(int i, ll val) {
        i += n;
        t[i] += val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = t[i] + t[i ^ 1];
        }
    }

    ll query(int l , int r) {
        l += n;
        r += n;
        ll ans = 0;

        for(; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans += t[l++];
            if (r&1) ans += t[--r];
        }

        return ans;
    }
};

void task() {
    int n;
    cin >> n;

    vector<ll> a(n);
    set<ll> vals;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        vals.insert(a[i]);
    }

    vector<ll> b;
    for(ll val : vals) b.push_back(val);
    
    SegTree segSum(b.size());
    SegTree segCnt(b.size());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        auto itr = lower_bound(b.begin(), b.end(), a[i]);
        int idx = itr - b.begin();

        ll added = a[i] * segCnt.query(0, idx) - segSum.query(0, idx);
        ans += added;

        segSum.add(idx, a[i]);
        segCnt.add(idx, 1);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}