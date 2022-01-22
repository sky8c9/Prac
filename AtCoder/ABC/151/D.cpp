#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<char>> grid;
vector<int> didj{1,0,-1,0,1};
int ans = 0;

void bfs(int i, int j) {
	vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
	queue<pair<int, int>> q;
	q.push({i,j});
	seen[i][j] = true;
	int d = 0;

	while(!q.empty()) {
		int size = q.size();

		while(size--) {
			auto[curI, curJ] = q.front(); q.pop();

			for(int k = 0; k < didj.size() - 1; k++) {
				int nI = curI + didj[k];
				int nJ = curJ + didj[k+1];

				if (nI < 0 || nI >= grid.size() || nJ < 0 || nJ >= grid[0].size()) continue;
				if (seen[nI][nJ] || grid[nI][nJ] != '.') continue;

				seen[nI][nJ] = true;
				q.push({nI,nJ});
			}
		}

		d++;
	}

	ans = max(ans, d-1);
}

void task() {
	int h,w;
	cin >> h >> w;

	grid.resize(h, vector<char>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if (grid[i][j] != '.') continue;
			bfs(i,j);
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}