#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
void task() {
	int n,m;
	cin >> n >> m;

	unordered_set<int> broken;
	vector<int> dp(n+2);
	while(m--) {
		int a;
		cin >> a;

		broken.insert(a);
	}

	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		if (broken.count(i + 1) == 0) {
			dp[i + 1] += dp[i];
			dp[i + 1] %= MOD;
		}

		if (broken.count(i + 2) == 0) {
			dp[i + 2] += dp[i];
			dp[i + 2] %= MOD;
		}
	}

	cout << dp[n] << endl;
}

int main() {
	task();
	return 0;
}
