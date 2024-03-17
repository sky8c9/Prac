#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

const ll MAX = 1e18;

void task() {
    int n;
    cin >> n;

    vector<vector<int>> p;
    p.resize(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> p[i][j];

    vector<vector<int>> r;
    r.resize(n, vector<int>(n - 1));
    rep(i, n) rep(j, n - 1) cin >> r[i][j];

    vector<vector<int>> d;
    d.resize(n - 1, vector<int>(n));
    rep(i, n - 1) rep(j, n) cin >> d[i][j];

    pair<ll, ll> dp[n][n][n][n];
    rep(i, n) rep(j, n) rep(ii, n) rep(jj, n) dp[i][j][ii][jj] = {MAX, 0};

    dp[0][0][0][0] = {0, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int ii = 0; ii < n; ii++) {
                for(int jj = 0; jj < n; jj++) {
                    if (dp[i][j][ii][jj].first == MAX) continue;

                    auto[curAction, curMoney] = dp[i][j][ii][jj];
                    if (i + 1 < n) {
                        int mxi = ii;
                        int mxj = jj;

                        ll need = max(0LL, d[i][j] - curMoney);
                        ll mul = (need + p[ii][jj] - 1) / p[ii][jj];

                        ll nAction = curAction + mul + 1;
                        ll nMoney = mul * p[ii][jj] + curMoney - d[i][j];
                        
                        if (p[i + 1][j] > p[ii][jj]) {
                            mxi = i + 1;
                            mxj = j;
                        } 

                        auto[dAction, dMoney] = dp[i + 1][j][mxi][mxj];
                        if (pair<ll, ll>{nAction, -nMoney} < pair<ll, ll>{dAction, -dMoney}) {
                            dp[i + 1][j][mxi][mxj] = {nAction, nMoney};
                        }
                    }

                    if (j + 1 < n) {
                        int mxi = ii;
                        int mxj = jj;

                        ll need = max(0LL, r[i][j] - curMoney);
                        ll mul = (need + p[ii][jj] - 1) / p[ii][jj];

                        ll nAction = curAction + mul + 1;
                        ll nMoney = mul * p[ii][jj] + curMoney - r[i][j];
                        
                        if (p[i][j + 1] > p[ii][jj]) {
                            mxi = i;
                            mxj = j + 1;
                        } 

                        auto[dAction, dMoney] = dp[i][j + 1][mxi][mxj]; 
                        if (pair<ll, ll>{nAction, -nMoney} < pair<ll, ll>{dAction, -dMoney}) {
                            dp[i][j + 1][mxi][mxj] = {nAction, nMoney};
                        }
                    }
                  
                }
            }
        }
    }

    ll ans = MAX;
    rep(i, n) rep(j, n) {
        ans = min(ans, dp[n - 1][n - 1][i][j].first);
    }
    
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}