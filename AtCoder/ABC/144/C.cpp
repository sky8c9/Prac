#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	ll n;
	cin >> n;

	ll ans = 1e18;
	for(ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans = min(ans, i - 1 + (n / i) - 1);
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}