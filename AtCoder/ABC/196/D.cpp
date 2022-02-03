#include <iostream>
#include <vector>

using namespace std;
vector<vector<bool>> seen;

int tiling(int i, int j, int a, int b, int h, int w) {
	if (a < 0 || b < 0) return 0;
	if (i == h) return 1;
	if (j == w) return tiling(i+1, 0, a, b, h, w);
	if (seen[i][j]) return tiling(i, j+1, a, b, h, w);

	int ans = 0;
	seen[i][j] = true;
	ans += tiling(i, j+1, a, b-1, h, w);

	for(int k = 0; k < 2; k++) {
		bool di = k == 0;
		bool dj = k == 1;

		if (i + di < h && j + dj < w && !seen[i + di][j + dj]) {
			seen[i + di][j + dj] = true;
			ans += tiling(i, j+1, a-1, b, h, w);
			seen[i + di][j + dj] = false;
		}
	}

	seen[i][j] = false;
	return ans;
}

void task() {
	int h,w,a,b;
	cin >> h >> w >> a >> b;

	seen = vector<vector<bool>>(h, vector<bool>(w));
	int ans = tiling(0,0,a,b,h,w);

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}