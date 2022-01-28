#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;
vector<int> color;
vector<vector<int>> adjL;
set<int> ans;
unordered_map<int,int> usedColor;

void dfs(int u, int p) {
	for(int v : adjL[u]) {
		if (v == p) continue;
		if (usedColor[color[v]] == 0) ans.insert(v+1);

		usedColor[color[v]]++;
		dfs(v,u); 
		usedColor[color[v]]--;
	}
}

void task() {
	int n;
	cin >> n;

	color = vector<int>(n);
	adjL = vector<vector<int>>(n);
	for(int&val : color) {
		cin >> val;
		usedColor[val] = 0;
	}

	for(int i = 0; i < n-1; i++) {
		int u,v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	ans.insert(1);
	usedColor[color[0]]++;
	dfs(0,-1);
	for(int v : ans) cout << v << endl;
}

int main() {
	task();
	return 0;
}