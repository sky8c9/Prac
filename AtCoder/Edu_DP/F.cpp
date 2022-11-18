#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void task() {
    string s,t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans = "";
    while(n > 0 && m > 0) {
        if (s[n-1] == t[m-1]) {
            ans += s[n-1];
            --n;--m;
        } else if (dp[n-1][m] > dp[n][m-1] && n > 0) --n;
        else --m; 
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}