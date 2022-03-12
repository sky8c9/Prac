#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> adjL;

void buildD(int u, int p, int d, vector<int>& dist) {
	dist[u] = d;
	for(int v : adjL[u]) {
		if (v == p) continue;
		buildD(v, u, d + 1, dist);
	}
}

void task() {
	int n,u,v;
	cin >> n >> u >> v;
	u--;v--;

	adjL = vector<vector<int>>(n);
	vector<int> distA(n);
	vector<int> distT(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;b--;

		adjL[a].push_back(b);
		adjL[b].push_back(a);
	}

	buildD(u, -1, 0, distT);
	buildD(v, -1, 0, distA);

	int ans = 0;
	for(int i = 0; i < n; i++) {
		if (distT[i] < distA[i]) {
			ans = max(ans, distA[i]);
		}
	}

	cout << (ans - 1) << endl;
}

int main() {
	task();
	return 0;
}