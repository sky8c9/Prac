#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long MAX = 1e18;

void task() {
	int h,w;
	long long c;
	cin >> h >> w >> c;

	vector<vector<int>> a(h, vector<int>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<long long>> minCost(h, vector<long long>(w, MAX));
	long long ans = MAX;

	for(int round = 1; round <= 2; round++) {
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				long long up = i == 0 ? MAX : minCost[i-1][j];
				long long left = j == 0 ? MAX : minCost[i][j-1];
				long long c2 = a[i][j] - c * (i + j);
				long long c1 = a[i][j] + c * (i + j);

				ans = min(ans, min(up,left) + c1);
				minCost[i][j] = min(c2, min(up, left));

			}
		}
		 
		reverse(a.begin(), a.end());
	}	

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}