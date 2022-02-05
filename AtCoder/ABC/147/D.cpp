#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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
	int n;
	cin >> n;

	vector<ll> A(n);
	for(ll&val : A) cin >> val;

	ll ans = 0;
	for(int i = 0; i < 60; i++) {
		int cnt1 = 0;

		for(int j = 0; j < n; j++) {
			if ((A[j] >> i) & 1) cnt1++;
		}

		ll val = pow_mod(2, i) * cnt1 % MOD * (n - cnt1);
		ans += val;
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}