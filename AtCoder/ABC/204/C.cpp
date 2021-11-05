#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, const vector<vector<int>>& adjL, vector<bool>& seen) {
	if (seen[u]) return 0;
	seen[u] = true;

	int sum = 1;
	for(int v : adjL[u]) {
		sum += dfs(v, adjL, seen);
	}

	return sum;
}

void task() {
	int n,m;
	int ans = 0;

	cin >> n >> m;
	vector<vector<int>> adjL(n);

	while(m--) {
		int u,v;
		cin >> u >> v;
		adjL[u-1].push_back(v-1);
	}

	for(int i = 0; i < n; i++) {
		vector<bool> seen(n,false);
		ans += dfs(i, adjL, seen);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}