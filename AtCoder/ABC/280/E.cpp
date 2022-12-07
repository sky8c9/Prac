#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
ll pow_mod(ll base, ll pow) {
	ll ans = 1;

	while(pow > 0) {
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
    ll n,p;
    cin >> n >> p;

    vector<ll> dp(n + 2);
    dp[0] = 1;
    ll inv = pow_mod(100, MOD - 2);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll prob_1 = (1ll - (p * inv % MOD) + MOD);
        ll prob_2 = p * inv % MOD;

        dp[i + 1] += dp[i] * prob_1;
        dp[i + 1] %= MOD;

        dp[i + 2] += dp[i] * prob_2;
        dp[i + 2] %= MOD;

        ans += dp[i];
        ans %= MOD;
    }

    cout << ans % MOD << endl;
}

int main() {
    task();
    return 0;
}