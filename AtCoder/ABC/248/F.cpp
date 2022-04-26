#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
	int n, p;
	cin >> n >> p;

	vector<vector<ll>> dp(n + 2, vector<ll>(2));
	dp[0][0] = dp[1][1] = 1;
	for(int i = 1; i < n; i++) {
		vector<vector<ll>> tmp(n + 2, vector<ll>(2));

		for(int j = 0; j < n; j++) {
			tmp[j][0] += dp[j][0] + dp[j][1];
			tmp[j][0] %= p;

			tmp[j + 1][0] += 3 * dp[j][0];
			tmp[j + 1][0] %= p;
			tmp[j + 1][1] += dp[j][1]; 
			tmp[j + 1][1] %= p;

			tmp[j + 2][1] += 2 * dp[j][0];
			tmp[j + 2][1] %= p;
		}

		dp = tmp;
	}

	for(int i = 1; i < n; i++) {
		cout << dp[i][0] << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}