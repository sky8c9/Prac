#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 1e18;
void task() {
	int n,k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	ll lo = 0;
	ll hi = 2e17 / k;
	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2 + 1;
		ll sum = 0;

		for(ll val : a) {
			sum += min(val, mid);
		}

		if (k * mid <= sum) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}

	cout << lo << endl;
}

int main() {
	task();
	return 0;
}