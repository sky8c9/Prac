#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 998244353;

struct SegTree {
    vector<int> t;
    int sz;

    SegTree(int n) {
        sz = n;
        t.resize(2 * n, 0);
    }

    void update(int i, int val) {
        i += sz;
        t[i] += val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = t[i] + t[i ^ 1]; 
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans += t[l++];
            if (r&1) ans += t[--r];
        }
        return ans;
    }
};

ll pow_mod(ll x, ll y) {
    ll ans = 1;
    x %= MOD;

    while(y) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }

        x *= x;
        x %= MOD;
        y >>= 1;
    }

    return ans;
}

void task() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    SegTree segN(n);
    ll cntN = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];

        cntN += segN.query(p[i] + 1, n);
        cntN %= MOD;
        segN.update(p[i], 1);
    }

    ll inner = ((ll) k * (k - 1)) % MOD;
    ll inv4 = pow_mod(4, MOD - 2);
    inner *= inv4;
    inner %= MOD;

    SegTree segK(n);
    ll cntK = 0;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        if (i >= k) {   
            ans += cntN - cntK + inner;
            ans += MOD;
            ans %= MOD;

            cntK -= segK.query(0, p[i - k]);
            cntK += MOD;
            cntK %= MOD;
            segK.update(p[i - k], -1);
        }

        if (i < n) {
            cntK += segK.query(p[i] + 1, n);
            cntK %= MOD;
            segK.update(p[i], 1);
        }
    }

    ll inv = pow_mod(n - k + 1, MOD - 2);
    ans *= inv;
    ans %= MOD;

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}