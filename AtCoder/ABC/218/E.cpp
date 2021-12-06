#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct dsu {
	vector<int> parents;
	vector<int> ranks;

	dsu(int n) {
		parents = vector<int>(n);
		ranks = vector<int>(n);

		for(int i = 0; i < n; i++) {
			parents[i] = i;
			ranks[i] = 1;
		}
	}

	int findP(int cur) {
		if (cur != parents[cur]) {
			parents[cur] = findP(parents[cur]);
		}
		return parents[cur];
	}

	bool join(int a, int b) {
		int pa = findP(a);
		int pb = findP(b);

		if (pa == pb) return false;
		if (ranks[pa] > ranks[pb]) parents[pb] = pa;
		else {
			if (ranks[pa] == ranks[pb]) ranks[pb]++;
			parents[pa] = pb;
		}

		return true;
	}
};

struct Edge {
	int u;
	int v;
	int cost;

	Edge () {
		u = -1;
		v = -1;
		cost = -1;
	}

	Edge(int pu, int pv, int pcost) {
		u = pu;
		v = pv;
		cost = pcost;
	}
};

void task() {
	int n,m;
	cin >> n >> m;
	dsu uf = dsu(n);

	long long ans = 0;
	vector<Edge> edges(m);

	for(int i = 0; i < m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		edges[i] = Edge(a-1,b-1,c);
	}

	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){return e1.cost < e2.cost;});
	for(auto&[u,v,c] : edges) {
		if (uf.join(u, v) == false && c >= 0) {
			ans += c;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}