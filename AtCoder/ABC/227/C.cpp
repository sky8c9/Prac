#include <iostream>

using namespace std;
using ll = long long;


void task() {
	ll n;
	cin >> n;

	ll ans = 0;
	for(long a = 1; a*a*a <= n; a++) {
		for(long b = a; a*b*b <= n; b++) {
			ans += n/(a*b) - b + 1;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}