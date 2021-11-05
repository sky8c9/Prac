#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	int sum;
	cin >> n;

	vector<bool> dp(100001);
	dp[0] = true;
	sum = 0;

	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		for(int j = 100000; j >= 0; j--) {
			if (dp[j]) {
				dp[j + val] = true;
			}
		}

		sum += val;
	}

	int ans = 100000;
	for(int i = 1; i < dp.size(); i++) {
		if (dp[i]) {
			ans = min(ans, max(i, sum - i));
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}