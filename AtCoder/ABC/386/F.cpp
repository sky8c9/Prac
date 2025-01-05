#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
const int MAX = 1e9;

void task() {
    int k;
    cin >> k;

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector(2 * k + 1, MAX));
    dp[0][k] = 0;
    for(int si = 0; si <= n; si++) {
        for(int di = -k; di <= k; di++) {
            int tj = si + di;
            int j = di + k;

            if (tj < 0 || tj > m) continue;
            if (si > 0 && j < 2*k) dp[si][j] = min(dp[si][j], dp[si - 1][j + 1] + 1);
            if (j > 0) dp[si][j] = min(dp[si][j], dp[si][j - 1] + 1);
            if (si > 0 && tj > 0) dp[si][j] = min(dp[si][j], dp[si - 1][j] + ((s[si - 1] == t[tj - 1]) ? 0 : 1));
                    
            if (si == n && tj == m && dp[si][j] <= k) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}