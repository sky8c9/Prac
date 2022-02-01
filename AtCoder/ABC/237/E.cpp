#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MAX = 1e18;
void task() {
	int n,m;
	cin >> n >> m;

	vector<int> h(n);
	vector<vector<int>> adjL(n);
	for(int&val : h) cin >> val;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> d(n, MAX);
	pq.emplace(0,0);
	d[0] = 0;
	while(!pq.empty()) {
		auto[curD,u] = pq.top(); pq.pop();
		if (curD != d[u]) continue;

		for(int v : adjL[u]) {
			int diff = max(0, h[v] - h[u]);

			if (curD + diff < d[v]) {
				d[v] = curD + diff;
				pq.emplace(d[v], v);
			}
		}
	}

	ll ans = 0;
	for(int i = 1; i < n; i++) {
		ans = max(ans, h[0] - h[i] - d[i]);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}