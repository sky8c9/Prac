#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const int MOD = 998244353;

void task() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> dp(m + 1, 1);
	for(int i = 2; i <= n; i++) {
		vector<ll> prefS(m + 1);
		for(int j = 1; j <= m; j++) {
			prefS[j] = prefS[j - 1] + dp[j];
			prefS[j] %= MOD; 
		}

		for(int j = 1; j <= m; j++) {
			int l = max(0, j - k);
			int r = min(m, j + k - 1);

			if (k == 0) dp[j] = prefS[m];
			else dp[j] = prefS[l] + prefS[m] - prefS[r];
			
			dp[j] += MOD;
			dp[j] %= MOD;
		}
	}

	ll ans = 0;
	for(int i = 1; i <= m; i++) {
		ans += dp[i];
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}