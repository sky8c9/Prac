#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
const string WORD = "chokudai";

void task() {
	string s;
	cin >> s;
	vector<vector<int>> dp(s.length() + 1, vector<int>(WORD.length() + 1));

	for(int i = 0; i < s.length() + 1; i++) dp[i][0] = 1;
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < WORD.length(); j++) {
			if (s[i] == WORD[j]) {
				dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
			} else {
				dp[i+1][j+1] = dp[i][j+1];
			}

			dp[i+1][j+1] %= MOD;
		}
	}

	cout << dp[s.length()][WORD.length()] << endl;
}

int main() {
	task();
	return 0;
}