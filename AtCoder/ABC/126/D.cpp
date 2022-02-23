#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	vector<vector<pair<int,int>>> adjL(n);
	vector<int> ans(n,-1);

	for(int i = 0; i < n - 1; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;v--;

		adjL[u].emplace_back(v,w);
		adjL[v].emplace_back(u,w);
	}

	queue<int> q;
	q.push(0);
	ans[0] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();

		for(auto[v,w] : adjL[u]) {
			if (ans[v] != -1) continue;
			ans[v] = (ans[u] + w) % 2;
			q.push(v);
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	task();
	return 0;
}