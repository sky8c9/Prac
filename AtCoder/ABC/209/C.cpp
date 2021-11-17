#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

void task() {
	int n;
	cin >> n;
	vector<int> c(n);

	for(int& val : c) cin >> val;
	sort(c.begin(), c.end());

	long long ans = 1;
	for(int i = 0; i < n; i++) {
		ans = (ans * (c[i] - i)) % MOD;
		if (ans == 0) break;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}