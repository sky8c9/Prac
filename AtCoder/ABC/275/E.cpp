#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
using ll = long long;

ll pow_mod(ll base, ll pow) {
    ll ans = 1;
	base %= MOD;

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
    int n,m,k;
    cin >> n >> m >> k;

    vector<ll> dp(n + 1);
    ll inv = pow_mod(m, MOD - 2);
    ll ans = 0;
    dp[0] = 1;
    for(int i = 0; i < k; i++) {
        vector<ll> tmp(n + 1);

        for(int cur = 0; cur < n; cur++) {
            for(int dice = 1; dice <= m; dice++) {
                int next = cur + dice;
                if (next > n) next = n - (next - n);
                tmp[next] += dp[cur] * inv % MOD;
                tmp[next] %= MOD;
            }
        }

        ans += tmp[n];
        ans %= MOD;
        dp = tmp;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}