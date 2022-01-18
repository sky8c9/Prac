#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dsu {
	vector<int> parents;
	vector<int> ranks;

	Dsu(int n) {
		parents = vector<int>(n);
		ranks = vector<int>(n);

		for(int i = 0; i < n; i++) {
			parents[i] = i;
		}
	}

	int findP(int cur) {
		if (cur != parents[cur]) {
			parents[cur] = findP(parents[cur]);
		}

		return parents[cur];
	}

	bool merge(int a, int b) {
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

	bool sameGroup(int a, int b) {
		int pa = findP(a);
		int pb = findP(b);
		return pa == pb;
	}
};

struct Edge {
	int u;
	int v;
	int w;
	int index;

	Edge(int uu, int vv, int ww, int i) {
		u = uu;
		v = vv;
		w = ww;
		index = i;
	}

	bool operator<(const Edge o) const {
		return w < o.w;
	}
};

void task() {
	int n,m,q;
	cin >> n >> m >> q;

	vector<Edge> E;
	for(int i = 0; i < m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		E.emplace_back(a,b,c,-1);
	}

	for(int i = 0; i < q; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		E.emplace_back(a,b,c,i);
	}

	sort(E.begin(), E.end());
	vector<bool> ans(q);
	Dsu uf(n);
	for(auto[u,v,w,index] : E) {
		if (index >= 0) {
			ans[index] = !uf.sameGroup(u,v);
		} else uf.merge(u,v);
	}

	for(int i = 0; i < q; i++) {
		if (ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main() {
	task();
	return 0;
}