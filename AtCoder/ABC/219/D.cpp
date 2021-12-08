#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9 + 1;
void task() {
	int n,x,y;
	cin >> n >> x >> y;

	vector dp(x + 1, vector<int>(y + 1, MAX));
	dp[0][0] = 0;
	while(n--) {
		int a,b;
		cin >> a >> b;
		vector temp(x + 1, vector<int>(y + 1, MAX));

		for(int i = 0; i <= x; i++) {
			for(int j = 0; j <= y; j++) {
				temp[i][j] = min(temp[i][j], dp[i][j]);
				int nextI = min(x, i + a);
				int nextJ = min(y, j + b);
				temp[nextI][nextJ] = min(temp[nextI][nextJ], dp[i][j] + 1);
			}
		}

		dp = temp;
	}

	int ans = dp[x][y] == MAX ? -1 : dp[x][y];
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}