#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;
void task() {
	int n,m;
	cin >> n >> m;

	vector<int> dp(1<<n, MAX);
	dp[0] = 0;
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;

		int bits = 0;
		for(int j = 0; j < b; j++) {
			int c;
			cin >> c;
			c--;

			bits |= (1 << c);
		}

		for(int j = 0; j < 1 << n; j++) {
			if (dp[j] == MAX) continue;
			dp[j | bits] = min(dp[j | bits], dp[j] + a);
		}
	}

	if (dp[(1<<n) - 1] == MAX) cout << -1 << endl;
	else cout << dp[(1<<n) - 1] << endl;
}

int main() {
	task();
	return 0;
}