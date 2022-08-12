#include <iostream>
#include <vector>
using namespace std;

void task() {
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> connect(n + 1, vector<bool>(n + 1));
	for(int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;
		connect[u][v] = true;
	}

	int ans = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if (!connect[i][j]) continue;
			for(int k = j + 1; k <= n; k++) {
				if (!connect[j][k]) continue;
				if (connect[i][k]) ans++;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}