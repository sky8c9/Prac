#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MAX = 1e18;
void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    int total = 0;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        int cnt = x > y ? 0 : (x + y + 1) / 2 - x;
        v.emplace_back(cnt, z);
        total += z;
    }

    vector<ll> dp(total + 1, MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = total - v[i].second + 1; j >= 0; j--) {
            if (dp[j] == MAX) continue;
            int nj = v[i].second + j;
            dp[nj] = min(dp[nj], dp[j] + v[i].first);
        }
    }

    ll ans = MAX;
    for(int i = (total + 1) / 2; i <= total; i++) ans = min(ans, dp[i]);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}