#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 2001;

vector<ll> fac(MAX);
vector<ll> inv(MAX);

const int MOD = 1e9 + 7;

ll pow_mod(ll x, ll y) {
	ll ans = 1;

	while(y > 0) {
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

void buildFac() {
	fac[0] = fac[1] = 1;
	inv[0] = inv[1] = 1;

	for(int i = 2; i < MAX; i++) {
		fac[i] = fac[i-1] * i % MOD;
		inv[i] = inv[i-1] * pow_mod(i, MOD - 2) % MOD;
	}
}

ll nck(int n, int k) {
	if (n < k) return 0;
	return ((fac[n] * inv[k]) % MOD * inv[n-k]) % MOD;
}

void task() {
	int n,k;
	cin >> n >> k;

	int numRed = n - k;
	buildFac();
	for(int i = 1; i <= k; i++) {
		ll ans = nck(numRed + 1, i) * nck(k - 1, i - 1);
		ans %= MOD;

		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}