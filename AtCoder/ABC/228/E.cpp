#include <iostream>

using namespace std;
using ll = long long;
const int MOD = 998244353;

ll pow_mod(ll base, ll pow, int mod) {
	ll ans = 1;
	base %= mod;

	while(pow > 0) {
		if (pow & 1) {
			ans *= base;
			ans %= mod;
		}

		base *= base;
		base %= mod;
		pow >>= 1;
	}

	return ans;
}

void task() {
	ll n,k,m;
	cin >> n >> k >> m;

	if (m % MOD == 0) cout << 0 << endl;
	else {
		ll r = pow_mod(k,n,MOD-1);
		ll ans = pow_mod(m,r,MOD);
		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}