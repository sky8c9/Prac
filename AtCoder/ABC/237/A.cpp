#include <iostream>

using namespace std;
using ll = long long;

void task() {
	ll n;
	cin >> n;

	ll hi = (ll) 1 << 31;
	ll lo = -hi;
	hi--;

	if (n >= lo && n <= hi) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}