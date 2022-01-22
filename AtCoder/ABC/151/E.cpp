#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<ll> fac;
vector<ll> infac;

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

void buildFac(int n) {
	fac = vector<ll>(n+1);
	infac = vector<ll>(n+1);
	fac[0] = fac[1] = 1;
	infac[0] = infac[1] = 1;

	for(int i = 2; i <= n; i++) {
		fac[i] = i * fac[i - 1] % MOD;
		infac[i] = pow_mod(i, MOD - 2) % MOD * infac[i - 1] % MOD;
	}
}

int ncr(int n, int r) {
	return fac[n] * infac[r] % MOD * infac[n-r] % MOD;
}

void task() {
	int n,k;
	cin >> n >> k;

	vector<ll> a(n);
	buildFac(n);

	for(ll& val : a) cin >> val;
	sort(a.begin(), a.end());

	ll ans = 0;
	for(int i = k - 1; i < n; i++) {
		ans += (a[i] * ncr(i, k-1)) % MOD;
		ans %= MOD;
	}

	for(int i = 0; i <= n - k; i++) {
		ans -= (a[i] * ncr(n-i-1, k-1)) % MOD;
		ans += MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}