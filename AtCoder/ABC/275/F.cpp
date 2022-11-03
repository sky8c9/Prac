#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;
void task() {
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    vector<vector<int>> dp(2, vector<int>(m + 1, MAX));
    dp[1][0] = 0;
    for(int i = 0; i < n; i++) {
        vector<vector<int>> tmp(2, vector<int>(m + 1, MAX));
        for(int j = 0; j <= m; j++) {
            if (j >= a[i]) tmp[1][j] = min(dp[0][j - a[i]], dp[1][j - a[i]]);
            tmp[0][j] = min(dp[1][j] + 1, dp[0][j]);
        }
        dp = tmp;
    }

    for(int i = 1; i <= m; i++) {
        int mn = min(dp[0][i], dp[1][i]);
        int ans = mn == MAX ? -1 : mn;
        cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}