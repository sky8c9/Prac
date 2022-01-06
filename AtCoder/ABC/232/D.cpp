#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void task() {
	int h,w;
	cin >> h >> w;

	vector<string> grid(h);
	for(int i = 0; i < h; i++) {
		cin >> grid[i];
	}

	vector dp(h+1, vector<int>(w+1));
	for(int i = h - 1; i >= 0; i--) {
		for(int j = w - 1; j >= 0; j--) {
			if (grid[i][j] == '#') continue;
			dp[i][j] = max(dp[i+1][j],dp[i][j+1]) + 1;
		}
	}

	cout << dp[0][0] << endl;
}

int main() {
	task();
	return 0;
}