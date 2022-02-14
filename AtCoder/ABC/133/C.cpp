#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	ll l,r;
	cin >> l >> r;

	r = min(l + 2019 * 2 - 1, r);
	int ans = 2019;
	for(ll i = l + 1; i <= r; i++) {
		for(ll j = l; j < i; j++) {
			int r = (i * j) % 2019;
			ans = min(ans, r);
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}