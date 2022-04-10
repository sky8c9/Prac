#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
const int MOD = 998244353;

ll pow_mod(ll a, ll b) {
	ll ans = 1;

	while(b > 0) {
		if (b & 1) {
			ans *= a;
			ans %= MOD;
		}

		a *= a;
		a %= MOD;
		b >>= 1;
	}

	return ans;
}

void task() {
	int n,l;
	cin >> n >> l;

	vector<int> bits(n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for(char c : s) {
			bits[i] |= 1 << (c - 'a');
		}
	}

	ll ans = 0;
	for(int i = 1; i < (1 << n); i++) {
		int intersect = (1 << 26) - 1;

		for(int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				intersect &= bits[j];
			}
		}

		int bitCnt = __builtin_popcount(i);
		int intersectCnt = __builtin_popcount(intersect);
		if (bitCnt & 1) {
			ans += pow_mod(intersectCnt, l);
		} else {
			ans -= pow_mod(intersectCnt, l);
			if (ans < 0) ans += MOD;
		}

		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}