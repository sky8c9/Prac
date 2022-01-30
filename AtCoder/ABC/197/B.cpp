#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void task() {
	int h,w,x,y;
	cin >> h >> w >> x >> y;
	x--;y--;

	vector<vector<char>> grid(h, vector<char>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 1;
	for(int i = y+1; i < w; i++) {
		if (grid[x][i] == '#') break;
		ans += 1;
	}

	for(int i = y-1; i >= 0; i--) {
		if (grid[x][i] == '#') break;
		ans += 1;
	}

	for(int i = x+1; i < h; i++) {
		if (grid[i][y] == '#') break;
		ans += 1;
	}

	for(int i = x-1; i >= 0; i--) {
		if (grid[i][y] == '#') break;
		ans += 1;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}