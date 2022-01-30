#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 2e10;
void task() {
	int n;
	cin >> n;

	vector<ll> A(n);
	for(ll& val : A) cin >> val;

	ll ans = MAX;
	for(int i = 0; i < (1 << (n-1)); i++) {
		ll ansOr = 0;
		ll ansXor = 0;

		for(int j = 0; j < n; j++) {
			ansOr |= A[j];

			if (i >> j & 1) {
				ansXor ^= ansOr;
				ansOr = 0;
			}
		}

		ansXor ^= ansOr;
		ans = min(ans, ansXor);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}