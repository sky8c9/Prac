#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

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
    int n, x;
    cin >> n >> x;

    vector<ll> t(n);
    for(ll& val : t) cin >> val;

    ll inv = pow_mod(n, MOD - 2);
    vector<ll> dp(x + 1);
    dp[0] = 1;
    for(int i = 0; i <= x; i++) {
        if (dp[i]) {
            for(int j = 0; j < n; j++) {
                if (i + t[j] > x) continue;
                dp[i + t[j]] += dp[i] * inv;
                dp[i + t[j]] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = x; i >= max(0ll, x - t[0] + 1); i--) {
        ans += dp[i] * inv;
        ans %= MOD;
    }

    cout << ans << endl;

}

int main() {
    task();
    return 0;
}