#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Dsu {
	int n;
	vector<int> parents;
	vector<int> ranks;

	Dsu(int size) {
		n = size;
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

	bool merge(int a, int b) {
		int pa = findP(a);
		int pb = findP(b);

		if (pa == pb) return false;
		if (ranks[pa] > ranks[pb]) {
			parents[pb] = pa;
		} else{
			if (ranks[pa] == ranks[pb]) ranks[pb]++;
			parents[pa] = pb;
		}

		n--;
		return true;
	}
};

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> edge(n);
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		edge[a].push_back(b);
	}

	Dsu uf(n);
	vector<int> ans(n);
	int cnt = 0;

	for(int u = n - 1; u >= 0; u--) {
		ans[u] = cnt;
		cnt++;

		for(int v : edge[u]) {
			bool flag = uf.merge(u,v);
			if (flag) {
				cnt--;
			}
		}
	}

	for(int val : ans) {
		cout << val << endl;
	}
}

int main() {
	task();
	return 0;
}