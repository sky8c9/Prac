#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> wv(n);
    for(int i = 0; i < n; i++) {
        cin >> wv[i].first >> wv[i].second;
    }

    vector<ll> dp(w + 1, -1);
    dp[0] = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = w - wv[i].first; j >= 0; j--) {
            if (dp[j] == -1) continue;
            dp[j + wv[i].first] = max(dp[j + wv[i].first], dp[j] + wv[i].second);
            ans = max(ans, dp[j + wv[i].first]);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}