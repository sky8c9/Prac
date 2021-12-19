#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;
const int MAX = 3000;

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	vector<int> prefS(MAX + 1);

	for(int& val : a) cin >> val;
	for(int& val : b) cin >> val;

	prefS[0] = 1;
	for(int i = 0; i <= n; i++) {
		vector<int> dp(MAX + 1);

		for(int j = 1; j <= MAX; j++) {
			prefS[j] = (prefS[j] + prefS[j - 1]) % MOD;
		}

		if (i == n) {
			cout << prefS[MAX] << endl;
			return;
		} else {
			for(int j = a[i]; j <= b[i]; j++) {
				dp[j] = prefS[j];
			}
			prefS = dp;
		}
	}
}

int main() {
	task();
	return 0;
}