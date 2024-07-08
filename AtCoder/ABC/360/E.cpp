#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const int MOD = 998244353;

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
    int n, k;
    cin >> n >> k;

    ll inv = powMod((ll) n * n, MOD - 2) * 2 % MOD;
    ll np1 = inv;
    ll p1 = (1ll - np1 * (n - 1) % MOD + MOD) % MOD;
    ll c = p1;

    for(int i = 0; i < k - 1; i++) {
        np1 = p1 * inv % MOD + np1 * c % MOD + np1 * inv % MOD * (n - 2);
        np1 %= MOD;

        p1 = (1ll - np1 * (n - 1) % MOD) + MOD;
        p1 %= MOD;
    }

    ll ans = 0;
    c = (ll) n * (n + 1) % MOD * powMod(2, MOD - 2) % MOD - 1 + MOD;
    c %= MOD;

    ans = p1 + c * np1 % MOD;
    ans %= MOD;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}