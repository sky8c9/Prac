#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

int compute(string a, string b) {
    string s = b + '#' + a;
    int n = s.size();
    
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++) {
        int j = dp[i - 1];
        while(j && s[i] != s[j]) {
            j = dp[j - 1];
        }

        if (s[i] == s[j]) ++j;
        if (j == b.size()) return 0;
        dp[i] = j;
    }

    return b.size() - dp[n - 1];
}

void task() {
    int n;
    cin >> n;

    vector<string> s(n);
    for(string& val : s) cin >> val;

    vector<vector<pair<int, int>>> adjL(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) continue;
            int cost = compute(s[i], s[j]);
            adjL[i].emplace_back(j, cost);
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, MAX));
    for(int i = 0; i < n; i++) {
        dp[1 << i][i] = s[i].size(); 
    }

    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if (i >> j & 1) {
                for(auto [nj, c] : adjL[j]) {
                    if (i >> nj & 1) continue;
                    
                    int ni = i | (1 << nj);
                    if (c) dp[ni][nj] = min(dp[ni][nj], dp[i][j] + c);
                    else dp[ni][j] = min(dp[ni][j], dp[i][j]);
                }
            }
        }
    }

    int ans = MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}