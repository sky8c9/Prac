#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& adjL, int u, int p) {
	cout << u << " ";

	for(int v : adjL[u]) {
		if (v == p) continue;
		dfs(adjL, v, u);
	}

	if (u > 1) cout << p << " ";
}

void task() {
	int n;
	cin >> n;

	vector<vector<int>> adjL(n + 1);

	for(int i = 0; i < n - 1; i++) {
		int a,b;
		cin >> a >> b;

		adjL[a].push_back(b);
		adjL[b].push_back(a);
	}

	for(int i = 1; i <= n; i++) {
		sort(adjL[i].begin(), adjL[i].end());
	}

	dfs(adjL, 1, 1);
}

int main() {
	task();
	return 0;
}
