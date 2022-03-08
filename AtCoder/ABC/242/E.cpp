#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MOD = 998244353;
const int MAX = 1e6;

void task() {
	int t;
	cin >> t;

	vector<long long> powMod(MAX + 1);
	powMod[0] = 1;
	for(int i = 1; i <= MAX; i++) {
		powMod[i] = powMod[i-1] * 26;
		powMod[i] %= MOD;
	}

	for(int i = 0; i < t; i++) {
		int n;
		string s;
		cin >> n >> s;

		long long ans = 0;
		int mid = (n + 1) / 2;
		for(int j = 0; j < mid; j++) {
			int val = s[j] - 'A';
			ans += val * powMod[mid - j - 1];
			ans %= MOD;
		}

		string tmp = s;
		for(int j = 0; j < mid; j++) {
			tmp[n - j - 1] = tmp[j];
		}

		if (tmp <= s) {
			ans++;
			ans%=MOD;
		}

		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}