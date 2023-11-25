#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
ll MAX = 1e18;

void task() {
    int n;
    cin >> n;

    vector<int> d(n);
    for(int& val : d) cin >> val;

    ll l1, c1, k1;
    cin >> l1 >> c1 >> k1;

    ll l2, c2, k2;
    cin >> l2 >> c2 >> k2;

    vector<ll> dp(k1 + 1, MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        vector<ll> tmp(k1 + 1, MAX);
        for(int j = 0; j <= k1; j++) {
            int mnLen = d[i] - j * l1;
            int mnK2 = mnLen <= 0 ? 0 : (mnLen + l2 - 1) / l2;
            if (mnK2 > k2) continue;

            for(int k = 0; k <= k1; k++) {
                if (dp[k] == MAX || dp[k] + mnK2 > k2) continue;
                if (k + j > k1) continue;
                tmp[k + j] = min(tmp[k + j], dp[k] + mnK2);
            }
        }
        dp = tmp;
    }

    ll ans = MAX;
    for(int i = 0; i <= k1; i++) {
        if (dp[i] == MAX) continue;
        ans = min(ans, dp[i] * c2 + i * c1);
    }

    ans = ans == MAX ? -1 : ans;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}