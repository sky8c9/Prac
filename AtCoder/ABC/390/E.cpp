#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, x;
    cin >> n >> x;

    vector<vector<pair<int, int>>> p(3);
    for(int i = 0; i < n; i++) {
        int v, a, c;
        cin >> v >> a >> c;
        --v;
        p[v].emplace_back(a, c);
    }

    vector<vector<int>> dp(3, vector<int>(x + 1, -1));
    for(int i = 0; i < 3; i++) {
        dp[i][0] = 0;

        for(auto[a, c] : p[i]) {
            for(int j = x - c; j >= 0; j--) {
                if (dp[i][j] == -1) continue;
                dp[i][j + c] = max(dp[i][j + c], dp[i][j] + a);
            }
        }

        for(int j = 1; j <= x; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }

    int ans = 0;
    vector<int> pts(3, 0);
    while(pts[0] + pts[1] + pts[2] <= x) {
        int mn = min(min(dp[0][pts[0]], dp[1][pts[1]]), dp[2][pts[2]]);
        ans = max(ans, mn);  

        if (dp[0][pts[0]] <= dp[1][pts[1]] && dp[0][pts[0]] <= dp[2][pts[2]]) ++pts[0];
        else if (dp[1][pts[1]] <= dp[0][pts[0]] && dp[1][pts[1]] <= dp[2][pts[2]]) ++pts[1];
        else ++pts[2];
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}