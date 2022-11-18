#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

const ll MAX = 1e18;
const int SZ = 1e5;

void task() {
    int n, w;
    cin >> n >> w;

    vector<pair<ll,ll>> wv;
    for(int i = 0; i < n; i++) {
        ll w,v;
        cin >> w >> v;
        wv.emplace_back(w,v);
    }

    vector<ll> dp(SZ + 1, MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = SZ; j >= 0; j--) {
            if (dp[j] == MAX) continue;
            dp[j + wv[i].second] = min(dp[j + wv[i].second], dp[j] + wv[i].first);
        }
    }

    int ans = 0;
    for(int i = 0; i <= SZ; i++) {
        if (dp[i] <= w) ans = max(ans, i);
    }
    cout << ans << endl;
 
}

int main() {
    task();
    return 0;
}