#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>> L;
int ans = 0;
ll target = 0;

void dfs(int curI, ll product) {
	if (curI >= L.size()) {
		if (product == target) ans++;
		return;
	}

	for(int val : L[curI]) {
		if (product * val > target) return;
		dfs(curI + 1, product * val);
	}
}

void task() {
	int n;
	ll x;
	cin >> n >> x;

	L = vector<vector<int>>(n);
	target = x;
	for(int i = 0; i < n; i++) {
		int l;
		cin >> l;

		L[i].resize(l);
		for(int j = 0; j < l; j++) {
			cin >> L[i][j];
		}

		sort(L[i].begin(), L[i].end());
	}

	dfs(0,1);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}