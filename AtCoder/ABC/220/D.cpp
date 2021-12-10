#include <iostream>
#include <vector>

const int MOD = 998244353;
using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> dp(10);
	int val;
	cin >> val;
	dp[val] = 1;

	for(int i = 1; i < n; i++) {
		cin >> val;
		vector<int> tmp(10);

		for(int j = 0; j < 10; j++) {
			if (dp[j] == 0) continue;
			tmp[(j + val) % 10] = (tmp[(j + val) % 10] + dp[j]) % MOD;
			tmp[(j * val) % 10] = (tmp[(j * val) % 10] + dp[j]) % MOD;
		}

		dp = tmp;
	}

	for(int i = 0; i < 10; i++) {
		cout << dp[i] << endl;
	}
}

int main() {
	task();
	return 0;
}