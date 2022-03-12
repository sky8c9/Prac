#include <iostream>

using namespace std;
using ll = long long;

void task() {
	ll n;
	cin >> n;

	ll ans = 0;
	if (n % 2 == 0) {
		ll num = 10;

		while(num <= n) {
			ans += n / num;
			num *= 5;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}