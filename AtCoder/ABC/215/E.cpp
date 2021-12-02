#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 998244353;
const int SIZE = 10;

void task() {
	int n;
	string s;
	cin >> n >> s;

	vector<vector<int>> dp(1 << SIZE, vector<int>(SIZE));
	int ans = 0;

	for(int i = 0; i < n; i++) {
		int iType = s[i] - 'A';

		for(int choices = 0; choices < (1 << SIZE); choices++) {
			if ((choices >> iType & 1) == 0) continue;

			// count number of configurations ending with s[i] contest
			ll count = 0;

			// prev contest and current contest have the same type
			count += dp[choices][iType];

			// prev contest and current contest have different types
			for(int pType = 0; pType < SIZE; pType++) {
				if (pType == iType) continue;
				if (choices >> pType & 1) {
					count += dp[choices ^ (1 << iType)][pType];
					count %= MOD;
				}
			}

			dp[choices][iType] = (dp[choices][iType] + count) % MOD;
			ans = (ans + count) % MOD;
		}

		dp[1 << iType][iType]++;
		ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}