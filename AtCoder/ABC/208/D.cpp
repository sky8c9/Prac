#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e9;

void task() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = MAX;
		}
	}

	while(m--) {
		int u,v;
		int c;

		cin >> u >> v >> c;
		dist[u-1][v-1] = c;
	}

	long long ans = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				if (dist[i][j] != MAX) ans += dist[i][j];
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}