#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> cost;
	for(int i = 0; i < n; i++) {
		ll a,b;
		cin >> a >> b;
		cost.emplace_back(b, a + b);
	}

	ll ans = 8e18;
	ll total = 0;
	for(int i = 0; i < min(x,n); i++) {
		total += cost[i].second;
		ans = min<ll>(ans, total + (ll) cost[i].first * (x - i - 1)); 
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}