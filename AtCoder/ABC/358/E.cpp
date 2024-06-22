#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAX = 1000;
const int CLEN = 26;

ll powMod(ll x, ll y) {
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
    int k;
    cin >> k;

    vector<int> c(CLEN + 1, 0);
    for(int i = 1; i <= CLEN; i++) {
        cin >> c[i];
    }

    vector<ll> fac(MAX + 1, 0);
    vector<ll> inv(MAX + 1, 0);
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i <= MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = powMod(i, MOD - 2) * inv[i - 1] % MOD;
    }

    auto nCr = [&](int n, int r) -> ll {
        return fac[n] * inv[n - r] % MOD * inv[r] % MOD;
    };

    vector<ll> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= CLEN; i++) {
        vector<ll> tmp = dp;

        for(int cnt = 1; cnt <= c[i]; cnt++) {
            for(int len = 0; len + cnt <= k; len++) {
                int nlen = len + cnt;
                tmp[nlen] += nCr(nlen, cnt) * dp[len];
                tmp[nlen] %= MOD;
            }
        }

        dp = tmp;
    }

    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}