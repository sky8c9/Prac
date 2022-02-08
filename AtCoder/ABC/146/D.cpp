#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int to;
	int index;

	Edge(int t, int i) {
		to = t;
		index = i;
	}
};

vector<int> ans;
vector<vector<Edge>> adjL;
int colorUsed;

void dfs(int u, int uc, int p) {
	int vc = 1;

	for(auto[v,index] : adjL[u]) {
		if (v == p) continue;
		if (vc == uc) vc++;

		ans[index] = vc;
		colorUsed = max(colorUsed, ans[index]);
		dfs(v,vc,u);
		vc++;
	}
}

void task() {
	int n;
	cin >> n;

	adjL = vector<vector<Edge>>(n);
	ans = vector<int>(n-1);
	for(int i = 0; i < n - 1; i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;

		adjL[a].emplace_back(Edge(b,i));
		adjL[b].emplace_back(Edge(a,i));
	}

	dfs(0,0,-1);
	cout << colorUsed << endl;
	for(int i = 0; i < n - 1; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	task();
	return 0;
}