#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6;

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

struct PFactor {
	vector<int> div;

	PFactor() {
		div = vector<int>(MAX + 1);
		for(ll i = 2; i <= MAX; i++) {
			if (div[i]) continue;
			div[i] = i;

			for(ll j = i*i; j <= MAX; j += i) {
				div[j] = i;
			}
		}
	}

	map<int, int> buildFac(int val) {
		map<int, int> ans;

		while(val > 1) {
			ans[div[val]]++;
			val /= div[val];
		}

		return ans;
	}
};

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	map<int, int> maxFreq; 
	PFactor pfactor;

	for(int& val : a) cin >> val;
	for(int i = 0; i < n; i++) {
		map<int, int> primes = pfactor.buildFac(a[i]);

		for(auto[pNum, freq] : primes) {
			maxFreq[pNum] = max(maxFreq[pNum], freq);
		}
	}

	ll lcm = 1;
	for(auto[pNum, freq] : maxFreq) {
		for(int i = 0; i < freq; i++) {
			lcm *= pNum;
			lcm %= MOD;
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += lcm * pow_mod(a[i], MOD - 2);
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}