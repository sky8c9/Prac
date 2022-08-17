#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Dsu {
	vector<int> parents;
	vector<int> ranks;
	vector<int> sizes;

	Dsu(int n) {
		parents.resize(n);
		ranks.resize(n);
		sizes.resize(n);
		for(int i = 0; i < n; i++) {
			parents[i] = i;
			ranks[i] = 1;
			sizes[i] = 1;
		}
	}

	int findP(int u) {
		if (u != parents[u]) {
			parents[u] = findP(parents[u]);
		}
		return parents[u];
	}

	int getSize(int u) {
		return sizes[parents[u]];
	}

	bool merge(int u, int v) {
		int pu = findP(u);
		int pv = findP(v);

		if (pu == pv) return false;
		if (ranks[pu] > ranks[pv]) {
			parents[pv] = pu;
			sizes[pu] += sizes[pv]; 
		} else {
			if (ranks[pu] == ranks[pv]) ranks[pv]++;
			parents[pu] = pv;
			sizes[pv] += sizes[pu];
		}

		return true;
	}
};

void task() {
	int n,m,e;
	cin >> n >> m >> e;

	vector<pair<int, int>> edges;
	vector<bool> del(e);
	for(int i = 0; i < e; i++) {
		int u,v;
		cin >> u >> v;
		--u;--v;

		edges.emplace_back(u, v);
		del[i] = false;
	}

	int q;
	cin >> q;
	vector<int> query(q);
	for(int i = 0; i < q; i++) {
		int val;
		cin >> val;
		--val;
		
		query[i] = val;
		del[val] = true;
	}

	Dsu uf(n + m);
	int cnt = 0;
	vector<bool> power(n + m, true);
	for(int i = 0; i < n; i++) power[i] = false;
	for(int i = 0; i < e; i++) {
		if (del[i]) continue;

		auto[u,v] = edges[i];
		if (uf.findP(u) == uf.findP(v)) continue;

		bool p1 = power[uf.findP(u)];
		bool p2 = power[uf.findP(v)];
		if (p1 ^ p2) {
			if (p1) cnt += uf.getSize(v);
			else cnt += uf.getSize(u);
		}

		uf.merge(u, v);
		power[uf.findP(u)] = p1 | p2;
	}

	vector<int> ans(q);
	for(int i = q - 1; i >= 0; i--) {
		ans[i] = cnt;

		auto[u,v] = edges[query[i]];
		if (uf.findP(u) == uf.findP(v)) continue;

		bool p1 = power[uf.findP(u)];
		bool p2 = power[uf.findP(v)];
		if (p1 ^ p2) {
			if (p1) cnt += uf.getSize(v);
			else cnt += uf.getSize(u);
		}

		uf.merge(u, v);
		power[uf.findP(u)] = p1 | p2;
	}

	for(int res : ans) cout << res << endl;
}

int main() {
	task();
	return 0;
}