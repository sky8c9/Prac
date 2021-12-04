#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAX = 5000;
void task() {
	int n;
	cin >> n;
	vector<pair<int, int>> ab(n);
	vector<int> dp(MAX + 1);

	for(int i = 0; i < n; i++) cin >> ab[i].first;
	for(int i = 0; i < n; i++) cin >> ab[i].second;

	sort(ab.begin(), ab.end());

	int ans = 0;
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		if (ab[i].first >= ab[i].second) {
			for(int total = ab[i].first - ab[i].second; total >= 0; total--) {
				ans = (ans + dp[total]) % MOD;
			}
		}

		for(int total = MAX - ab[i].second; total >= 0; total--) {
			if (dp[total]) dp[total + ab[i].second] = (dp[total + ab[i].second] + dp[total]) % MOD;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}