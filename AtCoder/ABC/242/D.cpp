#include <iostream>
#include <string>
#include <bit>
#include <bitset>

using namespace std;
using ll = long long;

void task() {
	string s;
	int q;
	cin >> s >> q;

	while(q--) {
		ll t,k;
		cin >> t >> k;

		k--;
		ll timeT = t > 60 ? 1e18 : 1ll << t;
		ll index = k / timeT;

		ll ones = __builtin_popcountll(k % timeT);
		ll rotations = (t - ones) + ones * 2;

		ll ansI =  ((s[index] - 'A') + rotations) % 3;
		char ansC = 'A' + ansI;

		cout << ansC << endl;
	}
}

int main() {
	task();
	return 0;
}