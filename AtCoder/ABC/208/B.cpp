#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;

void task() {
	int p;
	cin >> p;

	vector<int> fac(MAX + 1);
	fac[0] = 1;
	for(int i = 1; i <= MAX; i++) fac[i] = fac[i-1] * i;

	int ans = 0;
	for(int i = MAX; p > 0 && i > 0; i--) {
		if (fac[i] > p) continue;
		int q = p / fac[i];
		p -= q * fac[i];
		ans += q;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}