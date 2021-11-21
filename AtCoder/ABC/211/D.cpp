#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e6;

void task() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adjL(n);
	vector<int> dist(n, MAX);
	vector<int> dp(n);

	while(m--) {
		int u, v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	queue<int> q;
	q.push(0);
	dist[0] = 0;
	dp[0] = 1;

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : adjL[u]) {
			if (dist[v] == MAX) {
				dist[v] = dist[u] + 1;
				dp[v] = dp[u];
				q.push(v);
			} else if (dist[v] == dist[u] + 1) {
				dp[v] = (dp[v] + dp[u]) % MOD;
			}
		}
	}

	cout << dp[n-1] << endl;
}

int main() {
	task();
	return 0;
}