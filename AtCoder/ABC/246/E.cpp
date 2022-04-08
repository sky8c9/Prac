#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX = 1e9;
struct Point {
	int x;
	int y;
	int dir;

	Point(int xx, int yy, int pdir) {
		x = xx;
		y = yy;
		dir = pdir;
	}
};

void task() {
	int n, ax, ay, bx, by;
	cin >> n >> ax >> ay >> bx >> by;
	ax--;ay--;bx--;by--;

	vector<string> grid(n);
	vector<int> di{-1,1,-1,1};
	vector<int> dj{-1,-1,1,1};
	vector<vector<vector<bool>>> seen(n, vector<vector<bool>>(n, vector<bool>(4)));
	for(int i = 0; i < n; i++) cin >> grid[i];

	deque<Point> q;
	vector<vector<vector<int>>> distance(n, vector<vector<int>>(n, vector<int>(4, MAX)));
	for(int i = 0; i < 4; i++) {
		distance[ax][ay][i] = 1;
		q.push_back(Point(ax, ay, i));
	}

	while(!q.empty()) {
		int sz = q.size();

		while(sz--) {
			Point cur = q.front(); q.pop_front();
			auto[x, y, dir] = cur;

			if (x == bx && y == by) {
				cout << distance[x][y][dir] << endl;
				return;
			}

			if (seen[x][y][dir]) continue;
			seen[x][y][dir] = true;

			for(int i = 0; i < 4; i++) {
				int ni = x + di[i];
				int nj = y + dj[i];

				if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == '#') continue;
				int d = dir == i ? distance[x][y][dir] : distance[x][y][dir] + 1;

				if (d < distance[ni][nj][i]) {
					distance[ni][nj][i] = d;

					if (dir == i) q.push_front(Point(ni, nj, i));
					else q.push_back(Point(ni, nj, i));
				}
			} 
		}
	}

	cout << -1 << endl;
}

int main() {
	task();
	return 0;
}