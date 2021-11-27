#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dsu {
	vector<int> ranks;
	vector<int> parents;
	vector<int> counts;

	Dsu(int n) {
		ranks = vector<int>(n);
		parents = vector<int>(n);
		counts = vector<int>(n);

		for(int i = 0; i < n; i++) {
			ranks[i] = 1;
			parents[i] = i;
			counts[i] = 1;
		}
	}

	int find(int cur) {
		if (cur != parents[cur]) {
			parents[cur] = find(parents[cur]);
		}

		return parents[cur];
	}

	int findC(int cur) {
		return counts[find(cur)];
	}

	bool join(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa == pb) return false;

		if (ranks[pa] > ranks[pb]) {
			parents[pb] = pa;
			counts[pa] += counts[pb];
		} else {
			if (ranks[pa] == ranks[pb]) ranks[pb]++;
			parents[pa] = pb;
			counts[pb] += counts[pa];
		} 

		return true;
	}
};

struct Edge {
	int u;
	int v;
	int w;

	Edge() {
		u = -1;
		v = -1;
		w = -1;
	}

	Edge(int uu, int vv, int ww) {
		u = uu;
		v = vv;
		w = ww;
	}
};

void task() {
	int n;
	cin >> n;

	Dsu uf(n);
	vector<Edge> edges(n-1);
	for(int i = 0; i < n - 1; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;v--;
		edges[i] = Edge(u,v,w);
	}

	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {return e1.w < e2.w;});
	long long ans = 0;
	for(int i = 0; i < n - 1; i++) {
		const auto&[u,v,w] = edges[i];
		ans += (long long) uf.findC(u) * uf.findC(v) * w;
		uf.join(u,v);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}