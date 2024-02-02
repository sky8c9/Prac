#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 1e9;
void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, MAX));
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        dist[u][v] = w;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, MAX));
    for(int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for(int i = 0; i < (1 << n); i++) {
        set<int> seen;
        for(int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                seen.insert(j);
            }
        }

        for(int u : seen) {
            if (dp[i][u] == MAX) continue;
            for(int v = 0; v < n; v++) {
                if (seen.count(v) || dist[u][v] == MAX) continue;                
                dp[i | (1 << v)][v] = min(dp[i | (1 << v)][v] , dp[i][u] + dist[u][v]);
            }
        }
    }

    int ans = MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    if (ans == MAX) {
        cout << "No" << endl;
    } else {
        cout << ans << endl;
    }

}

int main() {
    task();
    return 0;
}