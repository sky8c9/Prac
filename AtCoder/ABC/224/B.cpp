#include <iostream>
#include <vector>

using namespace std;

void task() {
	int h,w;
	cin >> h >> w;

	vector<vector<int>> grid(h, vector<int>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}

	for(int i1 = 0; i1 < h; i1++) {
		for(int i2 = i1 + 1; i2 < h; i2++) {
			for(int j1 = 0; j1 < w; j1++) {
				for(int j2 = j1 + 1; j2 < w; j2++) {
					if (grid[i1][j1] + grid[i2][j2] > grid[i2][j1] + grid[i1][j2]) {
						cout << "No" << endl;
						return;
					}
				}
			}
		}
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}