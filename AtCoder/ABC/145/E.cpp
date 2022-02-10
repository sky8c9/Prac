#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n,t;
	cin >> n >> t;

	vector<pair<int, int>> ab;
	for(int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;

		ab.emplace_back(a,b);
	}

	sort(ab.begin(), ab.end());
	int ans = 0;
	vector<vector<int>> dp(n + 1, vector<int>(t));

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < t; j++) {
			dp[i][j] = max(dp[i][j], dp[i-1][j]);

			if (ab[i-1].first + j < t) {
				dp[i][j + ab[i-1].first] = max(dp[i][j + ab[i-1].first], dp[i-1][j] + ab[i-1].second);
			}
		}

		ans = max(ans, dp[i-1][t-1] + ab[i-1].second);
	}


	cout << ans << endl;

}

int main() {
	task();
	return 0;
}