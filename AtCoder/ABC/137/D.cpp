#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> jobs(m);
	for(int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;

		if (a > m) continue;
		jobs[m - a].push_back(b);
	}

	priority_queue<int> pq;
	ll ans = 0;
	for(int i = m - 1; i >= 0; i--) {
		for(int pay : jobs[i]) {
			pq.push(pay);
		}

		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}