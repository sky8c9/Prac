#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll n, k, d;
    cin >> n >> k >> d;

    vector<vector<ll>> dp(k + 1, vector<ll>(d, -1));
    dp[0][0] = 0; 
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;

        for(int j = k - 1; j >= 0; j--) {
            for(int r = 0; r < d; r++) {
                if (dp[j][r] == -1) continue;
                int rr = (dp[j][r] + a) % d;
                dp[j + 1][rr] = max(dp[j + 1][rr], dp[j][r] + a); 
            }
        }
    }

    cout << dp[k][0] << endl;
}

int main() {
    task();
    return 0;
}