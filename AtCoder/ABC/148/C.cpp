#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void task() {
	ll a,b;
	cin >> a >> b;

	ll ans = a * b / gcd(a,b);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}