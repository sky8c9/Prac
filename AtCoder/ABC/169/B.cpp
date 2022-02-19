#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MAX = 1e18;
void task() {
	int n;
	cin >> n;

	vector<ll> a(n);
	for(ll& val : a) {
		cin >> val;
		if (val == 0) {
			cout << 0 << endl;
			return;
		}
	}

	ll mul = 1;
	for(int i = 0; i < n; i++) {
		if (mul > (MAX / a[i])) {
			cout << -1 << endl;
			return;
		}

		mul *= a[i];
	}

	cout << mul << endl;
}

int main() {
	task();
	return 0;
}