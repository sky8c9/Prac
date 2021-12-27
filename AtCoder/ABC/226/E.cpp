#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;

vector<vector<int>> adjL;
vector<bool> visited;

void dfs(int u, int& cntV, int& cntE) {
	visited[u] = true;
	cntV += 1;
	cntE += adjL[u].size();

	for(int v : adjL[u]) {
		if (visited[v]) continue;
		dfs(v, cntV, cntE);
	}
}

void task() {
	int n,m;
	cin >> n >> m;

	adjL = vector<vector<int>>(n);
	visited = vector<bool>(n);
	while(m--) {
		int u,v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	int ans = 1;
	for(int i = 0; i < n; i++) {
		if (!visited[i]) {
			int cntV = 0;
			int cntE = 0;
			dfs(i,cntV,cntE);

			if (cntV * 2 == cntE) {
				ans *= 2;
				ans %= MOD;
			} else {
				ans = 0;
				break;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}