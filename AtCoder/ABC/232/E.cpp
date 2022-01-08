#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;
using ll = long long;

void task() {
	int h,w,k;
	cin >> h >> w >> k;
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;

	vector<vector<ll>> dp(2, vector<ll>(2));
	dp[x1 == x2][y1 == y2] = 1;

	while(k--) {
		vector<vector<ll>> tmp(2, vector<ll>(2));
		swap(tmp,dp);

		for(int j = 0; j < 2; j++) {
			dp[0][j] += tmp[0][j] * (h - 2) + tmp[1][j] * (h - 1);
			dp[0][j] %= MOD;

			dp[1][j] += tmp[0][j];
			dp[1][j] %= MOD;
		}

		for(int i = 0; i < 2; i++) {
			dp[i][0] += tmp[i][0] * (w - 2) + tmp[i][1] * (w-1);
			dp[i][0] %= MOD;

			dp[i][1] += tmp[i][0];
			dp[i][1] %= MOD;
		}
	}

	cout << dp[1][1] << endl;
}

int main() {
	task();
	return 0;
}