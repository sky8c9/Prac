#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int MOD = 1e9 + 7;

void task() {
	string L;
	cin >> L;

	// dpEqual[i]: # pairs having sum equal L up to i index
	// dpLess[i]: # pairs having sum less than L up to i index
	vector<int> dpEqual(L.size() + 1); 
	vector<int> dpLess(L.size() + 1);
	dpEqual[0] = 1;
	for(int i = 0; i < L.size(); i++) {
		if (L[i] == '0') {
			// a+b=0
			dpEqual[i + 1] = dpEqual[i];
			dpLess[i + 1] = dpLess[i];

			// a+b=1
			dpLess[i + 1] += 2 * dpLess[i] % MOD; // a = 0, b = 1 or a = 1, b = 0
			dpLess[i + 1] %= MOD;
		} else {
			// a+b=0
			dpLess[i + 1] = (dpEqual[i] + dpLess[i]) % MOD;

			// a+b=1
			dpEqual[i + 1] = (2 * dpEqual[i]) % MOD;
			dpLess[i + 1] += 2 * dpLess[i] % MOD;
			dpLess[i + 1] %= MOD;
		}
	}

	int ans = (dpEqual[L.size()] + dpLess[L.size()]) % MOD;
	cout <<  ans << endl;
}

int main() {
	task();
	return 0;
}