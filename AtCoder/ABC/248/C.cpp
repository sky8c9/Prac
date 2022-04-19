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

		for(int j = 0; j <= k; j++) {
			for(int z = 1; z <= m; z++) {
				if (j - z >= 0) {
					tmp[j] += dp[j - z];
					tmp[j] %= MOD;
				}
			}
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