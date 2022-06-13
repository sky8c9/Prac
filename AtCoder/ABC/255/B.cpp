#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using namespace std;
using ll = long long;

double dist(ll x1, ll y1, ll x2, ll y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void task() {
	int n,k;
	cin >> n >> k;

	vector<pair<int, int>> p;
	unordered_set<int> s;
	for(int i = 0; i < k; i++) {
		int idx;
		cin >> idx;
		s.insert(idx - 1);
	}

	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		p.emplace_back(x,y);
	}

	double ans = 0;
	for(int i = 0; i < n; i++) {
		if (s.count(i)) continue;
		double d = 1e9;

		for(int j : s) {
			d = min(d, dist(p[i].first, p[i].second, p[j].first, p[j].second));
		}

		ans = max(ans, d);
	}

	printf("%.8f\n", ans);
}

int main() {
	task();
	return 0;
}