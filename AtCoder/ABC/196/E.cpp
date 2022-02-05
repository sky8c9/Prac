#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MAX = 1e18;
void task() {
	int n;
	cin >> n;

	ll sum = 0;
	ll left = -MAX;
	ll right = MAX;
	for(int i = 0; i < n; i++) {
		ll a,t;
		cin >> a >> t;

		if (t == 1) {
			sum += a;
			left += a;
			right += a;
		} else if (t == 2) {
			left = max(left, a);
			right = max(right, a);
		} else {
			left = min(left, a);
			right = min(right, a);
		}
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int x;
		cin >> x;

		ll ans = sum + x;
		if (ans < left) cout << left << endl;
		else if (ans > right) cout << right << endl;
		else cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}