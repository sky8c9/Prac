#include <iostream>
#include <vector>

const int MOD = 998244353;
using namespace std;
using ll = long long;

void task() {
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>> adjL(n);

	while(m--) {
		int u,v;
		cin >> u >> v;
		u--;v--;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	vector<ll> dp(n);
	dp[0] = 1;

	for(int i = 0; i < k; i++) {
		ll sum = 0;
		vector<ll> prev(n);
		swap(prev, dp); 

		for(int u = 0; u < n; u++) {
			sum = (sum + prev[u]) % MOD;
		}

		for(int u = 0; u < n; u++) {
			dp[u] = (sum - prev[u] + MOD) % MOD;

			for(int v : adjL[u]) {
				dp[u] = (dp[u] - prev[v] + MOD) % MOD;
			}
		}
	}

	cout << dp[0] << endl;

}

int main() {
	task();
	return 0;
}