#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

void readMatrix(vector<vector<int>>& in) {
	for(int i = 0; i < in.size(); i++) {
		for(int j = 0; j < in[0].size(); j++) {
			cin >> in[i][j];
		}
	}
}

void task() {
	int h,w;
	cin >> h >> w;

	vector<vector<int>> a(h, vector<int>(w));
	vector<vector<int>> b(h, vector<int>(w));
	vector<vector<int>> diff(h, vector<int>(w));
	readMatrix(a);readMatrix(b);

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			diff[i][j] = abs(a[i][j] - b[i][j]);
		}
	}

	const int range = 2 * (80 * 160 + 1);
	vector<vector<bitset<range>>> dp(h+1, vector<bitset<range>>(w+1));
	dp[0][1][range / 2] = 1;
	dp[1][0][range / 2] = 1;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			dp[i][j] |= (dp[i-1][j] << diff[i-1][j-1]) | (dp[i-1][j] >> diff[i-1][j-1]);
			dp[i][j] |= (dp[i][j-1] << diff[i-1][j-1]) | (dp[i][j-1] >> diff[i-1][j-1]);
		}
	}

	int ans = range;
	for(int i = 0; i < range; i++) {
		if (dp[h][w][i]) {
			ans = min(ans, abs(i - range / 2));
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}