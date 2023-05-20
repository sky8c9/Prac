#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll pow_mod(ll base, ll pow) {
    ll ans = 1;

    while(pow) {
        if (pow & 1) {
            ans *= base;
            ans %= MOD;
        }

        base *= base;
        base %= MOD;
        pow >>= 1;
    }

    return ans;
}

void task() {
    ll n;
    cin >> n;

    unordered_map<ll, ll> dp;
    dp[n] = 1;
    function<ll(ll)> compute = [&] (ll cur) -> ll {
        if (cur > n) return 0;
        if (dp.count(cur)) return dp[cur];

        ll sum = 0;
        for(int i = 2; i <= 6; i++) {
            sum += compute(i * cur);
            sum %= MOD;
        }

        return dp[cur] = (pow_mod(5, MOD - 2) * sum) % MOD;
    };

    cout << compute(1) << endl;
}

int main() {
    task();
    return 0;
}