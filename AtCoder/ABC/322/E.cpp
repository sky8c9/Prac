#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 1e18;
void task() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> row(n, vector(k + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int& val : row[i]) {
            cin >> val;
        }
    }

    int sz = 0;
    for(int i = 0; i < k; i++) {
        sz = sz * 10 + p;
    }

    vector<ll> dp(sz + 1, MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = dp.size() - 1; j >= 0; j--) {
            if (dp[j] == MAX) continue;
            int cur = j;
            int nxt = 0;

            for(int l = 0; l < k; l++) {
                nxt += min(p, cur % 10 + row[i][k - l]) * pow(10, l);
                cur /= 10;
            }

            dp[nxt] = min(dp[nxt], dp[j] + row[i][0]);
        }
    }

    if (dp[sz] == MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[sz] << endl;
    }
}

int main() {
    task();
    return 0;
}