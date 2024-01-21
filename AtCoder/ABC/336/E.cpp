#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
using vvvll = vector<vector<vector<ll>>>;

void task() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        d[i] = s[i] - '0';
    }

    int mx_sum = 9 * n;
    ll ans = 0;
    for(int sum = 1; sum <= mx_sum; sum++) {
        vvvll dp(mx_sum + 1, vector<vector<ll>>(mx_sum + 1, vector<ll>(2, 0)));
        dp[0][0][0] = 1;

        for(int i = 0; i < n; i++) {
            vvvll tmp(mx_sum + 1, vector<vector<ll>>(mx_sum + 1, vector<ll>(2, 0)));

            for(int j = 0; j <= mx_sum; j++) {
                for(int r = 0; r < mx_sum; r++) {
                    for(int l = 0; l < 2; l++) {
                        for(int dd = 0; dd < 10; dd++) {
                            if (j + dd > sum) break;

                            int nj = j + dd;
                            int nr = (r * 10 + dd) % sum;
                            int nl = l;
                            if (l == 0) {
                                if (dd > d[i]) break;
                                if (dd < d[i]) nl = 1;
                            }

                            tmp[nj][nr][nl] += dp[j][r][l];
                        }
                    }
                }
            }

            dp = tmp;
        }

        ans += dp[sum][0][0];
        ans += dp[sum][0][1];
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}