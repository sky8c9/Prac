#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    int h, w, k;
    cin >> h >> w >> k;

    int si, sj;
    cin >> si >> sj;
    --si, --sj;

    vector<vector<int>> grid(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    int mxLen = h*w;
    vector<vector<vector<ll>>> dp(mxLen, vector<vector<ll>>(h, vector<ll>(w, -1)));
    vector<int> didj{-1, 0, 1, 0, -1};
    dp[0][si][sj] = 0;
    for(int l = 0; l < mxLen - 1; l++) {
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if (dp[l][i][j] == -1) continue;

                for(int d = 0; d < didj.size() - 1; d++) {
                    int ni = i + didj[d];
                    int nj = j + didj[d + 1];

                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    dp[l + 1][ni][nj] = max(dp[l + 1][ni][nj], dp[l][i][j] + grid[ni][nj]);
                }
            }
        }
    }

    ll ans = 0;
    for(int l = 0; l < mxLen; l++) {
        for(int i = 0; i < h; i++) {
            if (l > k) continue;

            for(int j = 0; j < w; j++) {
                if (dp[l][i][j] == -1) continue;

                ll cost = (ll) (k - l) * grid[i][j] + dp[l][i][j];
                ans = max(ans, cost);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}