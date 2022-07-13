#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<vector<pair<int, int>>> nums(n);
	map<int, int> mx;
	for(int i = 0; i < n; i++) {
		int m;
		cin >> m;

		for(int j = 0; j < m; j++) {
			int p,e;
			cin >> p >> e;
			nums[i].emplace_back(p, e);
			mx[p] = max(mx[p], e);
		}
	}

	map<int, int> freqMx;
	for(int i = 0; i < n; i++) {
		for(auto[p, e] : nums[i]) {
			if (mx[p] == e) freqMx[p]++;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		bool flag = false;

		for(auto[p, e] : nums[i]) {
			if (mx[p] == e && freqMx[p] == 1) {
				flag = true;
				break;
			}
		}

		if (flag) ans++;
	}

	if (ans == n)
		cout << ans << endl;
	else cout << (ans + 1) << endl;
}

int main() {
	task();
	return 0;
}