#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll compute(ll a, ll b) {
	return a*a*a + a*a*b + b*b*a + b*b*b;
}

void task() {
	ll n;
	cin >> n;

	ll ans = 5e18;
	for(int a = 0; a <= 1e6; a++) {
		ll lo = 0;
		ll hi = 1e6;

		while(lo < hi) {
			ll mid = lo + (hi - lo) / 2;
			ll val = compute(a, mid);

			if (val >= n) hi = mid;
			else lo = mid + 1;
		}

		ans = min(ans, compute(a, lo));
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}