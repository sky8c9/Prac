#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n,q;
	cin >> n >> q;

	vector<ll> a(n);
	vector<ll> prefS(n + 1);
	for(ll& val : a) cin >> val;

	sort(a.begin(), a.end());
	for(int i = 1; i <= n; i++) {
		prefS[i] = prefS[i - 1] + a[i - 1];
	}

	for(int i = 0; i < q; i++) {
		ll x;
		cin >> x;

		if (x < a[0] || x > a[n - 1]) cout << abs(prefS[n] - n * x) << endl;
		else {
			auto itr = lower_bound(a.begin(), a.end(), x);
			int len = itr - a.begin();
			ll left = x * len - prefS[len];
			ll right = prefS[n] - prefS[len] - x * (n - len);
			cout << (left + right) << endl;
		}
	}
}

int main() {
	task();
	return 0;
}