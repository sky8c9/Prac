#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timer = 0;
vector<int> in;
vector<int> out;
vector<vector<int>> dList, to;

void dfs(int cur, int depth) {
	in[cur] = timer++;
	dList[depth].push_back(in[cur]);

	for(int nb : to[cur]) {
		dfs(nb, depth + 1);
	}

	out[cur] = timer++;
}

void task() {
	int n;
	cin >> n;
	in = vector<int>(n);
	out = vector<int>(n);
	to = dList = vector<vector<int>>(n);

	for(int i = 0; i < n - 1; i++) {
		int parent;
		cin >> parent;
		to[parent - 1].push_back(i + 1);
	}

	dfs(0,0);
	int q;
	cin >> q;

	while(q--) {
		int u,d;
		cin >> u >> d;
		
		auto& l = dList[d];
		auto hi = lower_bound(l.begin(), l.end(), out[u-1]);
		auto lo = lower_bound(l.begin(), l.end(), in[u-1]);

		cout << hi - lo << endl;
	}
}

int main() {
	task();
	return 0;
}