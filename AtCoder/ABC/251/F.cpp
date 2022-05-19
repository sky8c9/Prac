#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjL;
vector<pair<int, int>> ans;
vector<bool> seen;

void dfs(int u, int p) {
	seen[u] = true;
	for(int v : adjL[u]) {
		if (v == p || seen[v]) continue;
		ans.emplace_back(u, v);
		dfs(v, u);
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	seen[u] = true;

	while(!q.empty()) {
		int sz = q.size();

		while(sz--) {
			int cur = q.front(); q.pop();

			for(int v : adjL[cur]) {
				if (seen[v]) continue;
				seen[v] = true;
				q.push(v);
				ans.emplace_back(cur, v);
			}
		}
	}
}

void task() {
	int n,m;
	cin >> n >> m;

	adjL.resize(n + 1);
	seen.resize(n + 1);
	for(int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	dfs(1, 0);
	seen.clear();
	seen.resize(n + 1);
	bfs(1);

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

int main() {
	task();
	return 0;
}