#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	ll x, a, d, n;
	cin >> x >> a >> d >> n;

	ll b = d * (n - 1) + a;
	ll l = min(a, b);
	ll r = max(a, b);

	if (x <= l) cout << l - x << endl;
	else if (x >= r) cout << x - r << endl;
	else {
		d = abs(d);
		ll ans = (x - l) % d;
		cout << min(ans, d - ans) << endl;
	}
}

int main() {
	task();
	return 0;
}