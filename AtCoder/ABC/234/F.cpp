#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 998244353;

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
	string s;
	cin >> s;

	vector<int> freq(26);
	for(char c : s) freq[c-'a']++;

	int n = s.length();
	buildFac(n);
	vector<ll> dp(n + 1);
	dp[0] = 1;
	for(char c = 0; c < 26; c++) {
		vector<ll> tmp(n + 1);

		for(int l = 0; l <= n; l++) {
			for(int cnt = 0; cnt <= min(l,freq[c]); cnt++) {
				tmp[l] += dp[l - cnt] * ncr(l, cnt);
				tmp[l] %= MOD;
			}
		}

		dp = tmp;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += dp[i];
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}