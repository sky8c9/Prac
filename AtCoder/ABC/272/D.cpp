#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
void task() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> ans(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	q.push({0,0});
	ans[0][0] = 0;
	int len = 1;
	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			auto [i,j] = q.front(); q.pop();
			for(int nj = 0; nj < n; nj++) {
				int deltaJ = (nj - j) * (nj - j);
				int deltaI = m - deltaJ;

				int st = sqrt(deltaI);
				if (st * st != deltaI) continue;

				vector<int> nis{i - st, i + st};
				for(int ni : nis) {
					if (ni >= 0 && ni < n && ans[ni][nj] == -1) {
						q.push({ni,nj});
						ans[ni][nj] = len;
					}
				}
			}
		}
		++len;
	}

	ans[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {
	task();
	return 0;
}