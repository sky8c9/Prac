#include <iostream>
#include <vector>

using namespace std;

vector<int> sumH(3);
vector<int> sumW(3);
vector<int> h(3);
vector<int> w(3);
int ans = 0;

void dfs(int pos) {
	if (pos == 4) {
		int col3_sum = (w[0] - sumW[0]) + (w[1] - sumW[1]);
		int row3_sum = (h[0] - sumH[0]) + (h[1] - sumH[1]);
		if (col3_sum >= h[2] || row3_sum >= w[2]) return;
		if (h[2] - col3_sum == w[2] - row3_sum) ans++;
		return;
	}

	for(int val = 1; val <= 30; val++) {
		int posI = pos / 2;
		int posJ = pos % 2;

		if (sumH[posI] + val >= h[posI] || sumW[posJ] + val >= w[posJ]) return;
		sumH[posI] += val;
		sumW[posJ] += val;
		dfs(pos + 1);
		sumH[posI] -= val;
		sumW[posJ] -= val;
	}
}

void task() {
	cin >> h[0] >> h[1] >> h[2] >> w[0] >> w[1] >> w[2];
	dfs(0);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}