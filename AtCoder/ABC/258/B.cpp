#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;
	vector<string> grid(n);
	vector<int> di{1,1,1,0,0,-1,-1,-1};
	vector<int> dj{1,0,-1,1,-1,1,0,-1};
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		grid[i] = s;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int d = 0; d < 8; d++) {
				int curI = i;
				int curJ = j;
				ll num = grid[i][j] - '0';

				for(int k = 0; k < n - 1; k++) {
					curI = (curI + di[d] + n) % n;
					curJ = (curJ + dj[d] + n) % n;
					num = num * 10 + (grid[curI][curJ] - '0');
				}

				ans = max(ans, num);
			}
		}
	}

	cout << ans << endl;	
}

int main() {
	task();
	return 0;
}