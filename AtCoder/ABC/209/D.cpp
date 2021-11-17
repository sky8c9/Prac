#include <iostream>
#include <vector>

using namespace std;
void coloring(vector<vector<int>>& adjL, vector<int>& color, int i, int val) {
	if (color[i] != -1) return;

	color[i] = val;
	for(int nb : adjL[i]) {
		coloring(adjL, color, nb, val ^ 1);
	}
}

void task() {
	int n, q;
	cin >> n >> q;

	vector<vector<int>> adjL(n);
	vector<int> color(n, -1);

	while(n-- > 1) {
		int u, v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	coloring(adjL, color, 0, 1);
	while(q--) {
		int u, v;
		cin >> u >> v;
		u--;v--;

		if (color[u] == color[v]) cout << "Town" << endl;
		else cout << "Road" << endl;
	}
}

int main() {
	task();
	return 0;
}