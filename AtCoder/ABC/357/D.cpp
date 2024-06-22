#include <iostream>

using namespace std;
using ll = long long;

const int MOD = 998244353;

ll powMod(ll x, ll y) {
    ll ans = 1ll;
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
    ll n;
    cin >> n;

    ll m = n;
    ll r = 1;
    while(m) {
        m /= 10;
        r *= 10;
    }

    ll inv = powMod(r - 1, MOD - 2);
    ll ans = n % MOD * (powMod(r, n) - 1 + MOD) % MOD * inv % MOD;

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}