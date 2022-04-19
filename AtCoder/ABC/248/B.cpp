#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

void task() {
	ll a,b,k;
	cin >> a >> b >> k;
	int ans = 0;

	while(a < b) {
		a *= k;
		ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}