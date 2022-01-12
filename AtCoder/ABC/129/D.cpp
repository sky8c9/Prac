#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void task() {
	int h,w;
	cin >> h >> w;

	vector<vector<int>> L(h+2, vector<int>(w+2));
	vector<vector<int>> D(h+2, vector<int>(w+2));
	vector<vector<int>> U(h+2, vector<int>(w+2));
	vector<vector<int>> R(h+2, vector<int>(w+2));
	vector<string> grid(h);

	int ans = 0;
	for(int i = 0; i < h; i++) cin >> grid[i];
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			if (grid[i-1][j-1] == '#') continue;
			else {
				L[i][j] += L[i][j-1] + 1;
				U[i][j] += U[i-1][j] + 1;
			}
		}
	}

	for(int i = h; i > 0; i--) {
		for(int j = w; j > 0; j--) {
			if (grid[i-1][j-1] == '#') continue;
			else {
				R[i][j] += R[i][j+1] + 1;
				D[i][j] += D[i+1][j] + 1;
				ans = max(ans, L[i][j] + U[i][j] + R[i][j] + D[i][j]);
			}
		}
	}

	cout << ans - 3 << endl;
}

int main() {
	task();
	return 0;
}