#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int&val : a) cin >> val;

	ll incl = a[0];
	ll excl = 0;
	ll ans = 0;
	for(int i = 1; i < n - 1; i++) {
		ll tmp = excl;
		excl = incl;
		incl = min(incl, tmp) + a[i];
	}

	ans = min(incl, excl) + a[n - 1];
	incl = a[1];
	excl = 0;
	for(int i = 2; i < n; i++) {
		ll tmp = excl;
		excl = incl;
		incl = min(incl, tmp) + a[i];
	}

	ans = min(ans, min(incl, excl) + a[0]);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}