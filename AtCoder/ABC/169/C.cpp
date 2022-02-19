#include <iostream>

using namespace std;
using ll = long long;

void task() {
	ll a;
	string b;
	cin >> a >> b;
	
	ll ans = 0;
	ans += a * (b[0] - '0') * 100;
	ans += a * (b[2] - '0') * 10;
	ans += a * (b[3] - '0');

	cout << ans / 100 << endl;
}

int main() {
	task();
	return 0;
}