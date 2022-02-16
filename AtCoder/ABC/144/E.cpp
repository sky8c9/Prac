#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	ll k;
	cin >> n >> k;

	vector<ll> a(n);
	vector<ll> f(n);
	for(ll& val : a) cin >> val;
	sort(a.begin(), a.end());

	for(ll& val : f) cin >> val;
	sort(f.begin(), f.end(), greater<ll>());

	ll l = 0;
	ll r = 1e12;
	while(l < r) {
		ll mid = l + (r - l) / 2;
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			sum += max(0ll, a[i] - mid / f[i]);
		}

		if (sum <= k) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
}

int main() {
	task();
	return 0;
}