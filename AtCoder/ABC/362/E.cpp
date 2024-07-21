#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

const int MOD = 998244353;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    vector<vector<map<int, ll>>> dp(n, vector<map<int, ll>>(n + 1));
    vector<ll> ans(n + 1);
    ans[1] = n;
    ans[2] = n * (n - 1) / 2;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ++dp[j][2][a[j] - a[i]];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int diff = a[i] - a[j];
            for(int len = 2; len < n; len++) {
                dp[i][len + 1][diff] += dp[j][len][diff];
                dp[i][len + 1][diff] %= MOD;
                
                ans[len + 1] += dp[j][len][diff];
                ans[len + 1] %= MOD;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}