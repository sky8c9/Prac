#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
const int MOD = 998244353;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> inD(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        ++inD[a[i]];
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if (inD[i] == 0) q.push(i);
    }

    vector<vector<ll>> dp(n, vector<ll>(m, 1));
    while(q.size()) {
        int i = q.front(); q.pop();
        --inD[a[i]];
        if (inD[a[i]] == 0) q.push(a[i]);

        ll sum = 0;
        for(int j = 0; j < m; j++) {
            sum += dp[i][j];
            sum %= MOD;

            dp[a[i]][j] *= sum;
            dp[a[i]][j] %= MOD;
        }
    }

    ll ans = 1;
    for(int i = 0; i < n; i++) {
        if (inD[i]) {
            vector<ll> cnt(m, 1);
            while(inD[i]) {
                for(int j = 0; j < m; j++) {
                    cnt[j] *= dp[i][j];
                    cnt[j] %= MOD;
                }

                inD[i] = 0;
                i = a[i];
            }

            ll sum = 0;
            for(int j = 0; j < m; j++) {
                sum += cnt[j];
                sum %= MOD;
            }

            ans *= sum;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}