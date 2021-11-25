#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;
const vector<int> dxdy = {1,0,-1,0,1};

void task() {
	int h,w;
	cin >> h >> w;

	vector<vector<char>> grid(h, vector<char>(w));
	vector<vector<int>> dist(h, vector<int>(w));

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >>grid[i][j];
			dist[i][j] = MAX;
		}
	}

	deque<pair<int,int>> dq;
	dist[0][0] = 0;
	dq.push_front(make_pair(0,0));

	while(!dq.empty()) {
		auto [i,j] = dq.front(); dq.pop_front();

		// direct connected cells
		for(int k = 0; k < dxdy.size() - 1; k++) {
			int ni = i + dxdy[k];
			int nj = j + dxdy[k+1];

			if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
			if (grid[ni][nj] == '#') continue;
			if (dist[i][j] < dist[ni][nj]) {
				dist[ni][nj] = dist[i][j];
				dq.push_front(make_pair(ni,nj));
			}
		}

		// cells can be reached by one punch
		for(int r = -2; r <= 2; r++) {
			for(int c = -2; c <= 2; c++) {
				if (abs(r) + abs(c) == 4) continue;
				int ni = i + r;
				int nj = j + c;

				if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
				if (dist[i][j] + 1 < dist[ni][nj]) {
					dist[ni][nj] = dist[i][j] + 1;
					dq.push_back(make_pair(ni,nj));
				}
			}
		}
	}

	cout << dist[h-1][w-1] << endl;
}

int main() {
	task();
	return 0;
}