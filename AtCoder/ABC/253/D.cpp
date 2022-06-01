#include <iostream>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

void task() {
	ll n, a, b;
	cin >> n >> a >> b;

	ll ans = n * (n + 1) / 2;
	ll cntA = n / a;
	ll cntB = n / b;

	ll sumA = a * cntA * (cntA + 1) / 2;
	ll sumB = b * cntB * (cntB + 1) / 2;

	ll lcmAB = (a * b) / gcd(a, b);
	ll cntAB = n / lcmAB;
	ll sumAB = lcmAB * cntAB * (cntAB + 1) / 2;

	ans = ans - sumA - sumB + sumAB;
	cout << ans << endl;

}

int main() {
	task();
	return 0;
}