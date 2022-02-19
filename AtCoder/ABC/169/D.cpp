#include <iostream>
#include <unordered_set>

using namespace std;
using ll = long long;

void task() {
	ll n;
	cin >> n;

	int ans = 0;
	unordered_set<ll> seen;
	while(n > 1) {
		ll tmp = n;
		bool found = false;

		for(ll i = 2; i * i <= n && !found; i++) {
			if (tmp % i) continue;

			ll val = 1;
			while(tmp % i == 0) {
				val *= i;
				if (seen.count(val) == 0) {
					seen.insert(val);
					found = true;
					n /= val;
					ans++;
					break;
				}
				tmp /= i;
			}
		}

		if (!found) {
			if (tmp != 1 && seen.count(n) == 0) ans++;
			break;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}