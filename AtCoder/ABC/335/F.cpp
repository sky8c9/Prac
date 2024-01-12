#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
const int MOD = 998244353;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& val : a) cin >> val;

    int n2 = (int) sqrt(n);
    vector<ll> dp(n);
    vector<vector<ll>> s(n, vector<ll>(n2 + 1, 0));

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n2; j++) {
            dp[i] += s[i][j];
            dp[i] %= MOD;
        }

        if (a[i] > n2) {
            for(int j = i + a[i]; j < n; j+=a[i]) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        } else if (i + a[i] < n) {
            s[i + a[i]][a[i]] += dp[i];
            s[i + a[i]][a[i]] %= MOD;
        }

        for(int j = 1; j <= n2; j++) {
            if (i + j >= n) break;
            s[i + j][j] += s[i][j];
            s[i + j][j] %= MOD;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}