#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const int MOD = 998244353;

void task() {
	int n,m,k;
	cin >> n >> m >> k;

	vector<ll>dp(k + 1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		vector<ll> tmp(k + 1);
		vector<ll> prefS(k + 1);

		prefS[0] = dp[0];
		for(int j = 1; j <= k; j++) {
			prefS[j] = prefS[j - 1] + dp[j];
			tmp[j] += prefS[j - 1] - (j - m - 1 < 0 ? 0 : prefS[j - m - 1]);
			tmp[j] %= MOD;
		}

		dp = tmp;
	}
	
	ll ans = 0;
	for(int i = 1; i <= k; i++) {
		ans += dp[i];
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}