#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	int w;
	cin >> n >> w;

	vector<pair<int, int>> ab(n);
	for(int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		ab.emplace_back(a,b);
	}

	sort(ab.rbegin(), ab.rend());
	ll ans = 0;

	for(auto&[curD,curW] : ab) {
		if (w <= 0) break;
		int mw = min(curW, w);
		ans = ans + (ll) curD * mw;
		w -= mw;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}