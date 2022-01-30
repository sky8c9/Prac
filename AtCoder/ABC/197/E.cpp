#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 2e9;
const ll LLMAX = 1e18;

void task() {
	int n;
	cin >> n;

	vector<int> l(n, MAX);
	vector<int> r(n, -MAX);

	for(int i = 0; i < n; i++) {
		int x,c;
		cin >> x >> c;
		c--;

		l[c] = min(x, l[c]);
		r[c] = max(x, r[c]);
	}

	vector<pair<int, int>> nodes;
	nodes.emplace_back(0,0);
	for(int i = 0; i < n; i++) {
		if (l[i] != MAX && r[i] != -MAX) {
			nodes.emplace_back(l[i],r[i]);
		}
	}
	nodes.emplace_back(0,0);

	vector<ll> dp(2);
	for(int i = 1; i < nodes.size(); i++) {
		vector<ll> tmp = dp;
		dp[0] = LLMAX;
		dp[1] = LLMAX;

		for(int j = 0; j < 2; j++) {
			int prev = j == 0 ? nodes[i-1].first : nodes[i-1].second;

			dp[0] = min(dp[0], tmp[j] + abs(nodes[i].second-prev) + (nodes[i].second-nodes[i].first));
	      	dp[1] = min(dp[1], tmp[j] + abs(nodes[i].first-prev) + (nodes[i].second-nodes[i].first));
		}
	}

	cout << dp[0] << endl;
}

int main() {
	task();
	return 0;
}