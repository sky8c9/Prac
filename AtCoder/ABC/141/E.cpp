#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void task() {
	int n;
	string s;
	cin >> n >> s;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i; j < n; j++) {
			if (s[i] == s[j]) {
				dp[i][j] = min(dp[i+1][j+1] + 1, j - i);
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}