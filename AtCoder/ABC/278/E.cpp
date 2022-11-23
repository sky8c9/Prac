#include <iostream>
#include <vector>

using namespace std;
void task() {
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;

    vector<vector<int>> grid(H + 1, vector<int>(W + 1));
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int>>> dp(H + 1, vector<vector<int>>(W + 1, vector<int>(301)));
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            for(int k = 1; k <= 300; k++) {
                dp[i][j][k] = (k == grid[i][j] ? 1 : 0) + dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k]; 
            }          
        }
    }

    for(int i = 1; i + h - 1 <= H; i++) {
        for(int j = 1; j + w - 1 <= W; j++) {
            vector<int> cnt(301);
            for(int k = 1; k <= 301; k++) {
                cnt[k] = dp[i+h-1][j+w-1][k] - dp[i-1][j+w-1][k] - dp[i+h-1][j-1][k] + dp[i-1][j-1][k];
            }

            int ans = 0;
            for(int k = 1; k <= 301; k++) {
                if (dp[H][W][k] > cnt[k]) ++ans;
            }

            cout << ans << " ";
        }

        cout << endl;
    }
}

int main() {
    task();
    return 0;
}