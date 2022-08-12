#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int mod = 998244353;

vector<int> a;
int dfs(int n, int len, int sz, int r, vector<vector<vector<int>>>& dp) {
	if (len == 0) return r == 0;
	if (n == 0) return 0;
	if (dp[n][len][r] != -1) return dp[n][len][r];

	int ans = 0;
	ans = dfs(n - 1, len, sz, r, dp) % mod;
	ans = (ans + dfs(n - 1, len - 1, sz, (r + a[n - 1]) % sz, dp)) % mod;
	return dp[n][len][r] = ans;
}

void task() {
	int n;
	cin >> n;

	a.resize(n);
	for(int&val : a) cin >> val;

	int ans = 0;
	for(int len = 1; len <= n; len++) {
		vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(len + 1, vector<int>(len, -1)));
		int val = dfs(n, len, len, 0, dp);
		ans += val;
		ans %= mod;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}