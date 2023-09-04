#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<ll> dp(1<<n, 0);
    vector<vector<int>> dist(n - 1, vector<int>(n));
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if (i >> j & 1) continue;          
            for(int k = 0; k < n; k++) {
                if (k == j || ((i >> k) & 1)) continue;
                int ni = i | (1 << j) | (1 << k);
                dp[ni] = max(dp[ni], dp[i] + dist[j][k]); 
            }
            break;
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}

int main() {
    task();
    return 0;
}