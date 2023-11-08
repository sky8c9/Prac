#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll pow_mod(long long base, long long pow) {
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
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll& val : a) cin >> val;

    ll inv = pow_mod(n, MOD - 2);
    ll ans = (inv * a[n - 1]) % MOD;
    for(int i = n - 2; i >= 0; i--) {
        ans += inv * (a[i] + ans);
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}