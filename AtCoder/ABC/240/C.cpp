#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n,x;
	cin >> n >> x;

	vector<vector<bool>> dp(n + 1, vector<bool>(x + 1));
	dp[0][0] = true;

	for(int i = 1; i <= n; i++) {
		int a,b;
		cin >> a >> b;

		for(int j = 0; j <= x; j++) {
			if (!dp[i-1][j]) continue;
			if (j + a <= x) dp[i][j + a] = true;
			if (j + b <= x) dp[i][j + b] = true;
		}
	}

	if (dp[n][x]) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}