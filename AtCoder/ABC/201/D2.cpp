#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void task() {
	int h,w;
	string s;

	// input
	cin >> h >> w;
	vector<vector<int>> val(h, vector<int>(w));
	vector<vector<int>> dp(h, vector<int>(w));

	for(int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < w; j++) {
			val[i][j] = s[j] == '+' ? 1 : -1;
		}
	}

	// dp compute
	for(int i = h - 1; i >= 0; i--) {
		for(int j = w - 1; j >= 0; j--) {
			if (i == h - 1 && j == w - 1) continue;

			dp[i][j] = INT_MIN;
			if (i + 1 < h) {
				dp[i][j] = max(dp[i][j], val[i+1][j] - dp[i+1][j]); 
			}
			if (j + 1 < w) {
				dp[i][j] = max(dp[i][j], val[i][j+1] - dp[i][j+1]); 
			} 
		}
	}

	// output
	if (dp[0][0] > 0) {
		cout << "Takahashi" << endl;
	} else if (dp[0][0] < 0) {
		cout << "Aoki" << endl;
	} else {
		cout << "Draw" << endl;
	}
}

int main() {
	task();
	return 0;
}