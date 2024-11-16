#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MAX = 1e18;

void task() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<ll> t(n);
    for(ll& val : t) cin >> val;

    vector<ll> days;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            days.push_back(t[i] + (ll) j * x);
        }
    }

    days.push_back(-MAX);
    sort(days.begin(), days.end());
    days.erase(unique(days.begin(), days.end()), days.end());

    vector<ll> prefS(n + 1);
    for(int i = 0; i < n; i++) prefS[i + 1] = prefS[i] + t[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(days.size(), MAX));
    for(int i = 0; i < dp.size(); i++) dp[0][i] = 0;
    for(int i = 0; i < n; i++) {
        for(int kk = 1; kk <= k; kk++) {
            if (i + kk > n) continue;
            for(int j = 1; j < days.size(); j++) {
                int prev = upper_bound(days.begin(), days.end(), days[j] - x) - days.begin() - 1;
                int pos = upper_bound(t.begin(), t.end(), days[j]) - t.begin() - 1;
                if (pos < i + kk - 1) continue;

                ll cost = days[j] * kk - (prefS[i + kk] - prefS[i]);
                dp[i + kk][j] = min(dp[i + kk][j], dp[i + kk][j - 1]);
                dp[i + kk][j] = min(dp[i + kk][j], dp[i][prev] + cost);
            }
        }
    }

    ll ans = MAX;
    for(int i = 1; i < days.size(); i++) ans = min(ans, dp[n][i]);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}