#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
vector<ll> fac;
vector<ll> inv;

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

void buildFac(int n) {
	fac = vector<ll>(n + 1);
	inv = vector<ll>(n + 1);

	fac[0] = 1; fac[1] = 1;
	inv[0] = 1; inv[1] = 1; 
	for(int i = 2; i <= n; i++) {
		fac[i] = i * fac[i-1];
		fac[i] %= MOD;
		inv[i] = pow_mod(i, MOD - 2) % MOD * inv[i-1] % MOD;
	}
}

ll ncr(int n, int r) {
	return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void task() {
	int x,y;
	cin >> x >> y;

	if ((x + y) % 3) {
		cout << 0 << endl;
		return;
	}

	int step = (x + y) / 3;
	int x0 = x - step;
	int y0 = y - step;
	if (x0 < 0 || y0 < 0) {
		cout << 0 << endl;
		return;
	}

	buildFac(x0 + y0);
	ll ans = ncr(x0 + y0, x0);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}