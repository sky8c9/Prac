#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 1e9;

vector<vector<int>> adjL;
vector<vector<int>> radjL;

struct Edge {
	int u,v,c;

	Edge(int uu, int vv, int cc) {
		u = uu;
		v = vv;
		c = cc;
	}
};

void reachable(int u, vector<bool>& seen, vector<vector<int>>& nb) {
	for(int v : nb[u]) {
		if (seen[v]) continue;
		seen[v] = true;
		reachable(v, seen, nb);
	}
}

vector<bool> validNode() {
	int n = adjL.size();
	vector<bool> ans(n);
	vector<bool> from1(n);
	vector<bool> fromN(n);

	from1[0] = true;
	fromN[n-1] = true;
	reachable(0, from1, adjL);
	reachable(n - 1, fromN, radjL);

	for(int i = 0; i < n; i++) {
		ans[i] = from1[i] && fromN[i];
	}

	return ans;
}

void task() {
	int n,m,p;
	cin >> n >> m >> p;

	adjL = vector<vector<int>>(n);
	radjL = vector<vector<int>>(n);
	vector<Edge> edges;
	for(int i = 0; i < m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		--a;--b;

		edges.emplace_back(a, b, p-c);
		adjL[a].push_back(b);
		radjL[b].push_back(a);
	}	

	vector<bool> vNodes = validNode();
	vector<int> dist(n, MAX);
	dist[0] = 0;

	for(int i = 0; i <= n; i++) {
		bool flag = false;

		for(int j = 0; j < m; j++) {
			auto[u, v, c] = edges[j];
			if (dist[u] == MAX || !vNodes[u] || !vNodes[v]) continue;
			if (dist[u] + c < dist[v]) {
				dist[v] = dist[u] + c;
				flag = true;
			}
		}

		if (flag && i == n) {
			cout << -1 << endl;
			return;
		}

		if (!flag) break;
	}

	int ans = -dist[n-1];
	ans = max(ans, 0);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}