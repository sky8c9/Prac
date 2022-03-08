#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;

void task() {
	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(11));
	for(int i = 1; i <= 9; i++) dp[1][i] = 1;
	for(int i = 2; i <= n ; i++) {
		for(int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD + dp[i-1][j+1];
			dp[i][j] %= MOD;
		}
	}

	int ans = 0;
	for(int i = 1; i <= 9; i++) {
		ans += dp[n][i];
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}