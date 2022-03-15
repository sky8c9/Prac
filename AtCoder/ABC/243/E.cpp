#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

struct Edge {
	int u;
	int v;
	int c;

	Edge(int uu, int vv, int cc) {
		u = uu;
		v = vv;
		c = cc;
	}
};

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<ll>> dist(n, vector<ll>(n, MAX));
	vector<Edge> edges;
	for(int i = 0; i < m ; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;

		edges.emplace_back(a,b,c);
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 0;
	for(auto[u,v,c] : edges) {
		bool flag = false;

		for(int k = 0; k < n; k++) {
			if (dist[u][k] + dist[k][v] <= c) {
				flag = true;
				break;
			}
		}

		if (flag) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}