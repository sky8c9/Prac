#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void task() {
	ll a,b,x;
	cin >> a >> b >> x;

	ll l = 0;
	ll r = 1e9;
	while(l < r) {
		ll mid = l + (r - l) / 2 + 1;
		string num = to_string(mid);
		ll val = a * mid + b * num.length();

		if (val <= x) l = mid;
		else r = mid - 1;
	}

	cout << l << endl;
}

int main() {
	task();
	return 0;
}