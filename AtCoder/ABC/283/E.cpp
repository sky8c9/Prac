#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e5;

void task() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<int>> flipped_grid(h, vector<int>(w));
    vector<vector<bool>> lr_states(h, vector<bool>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
            flipped_grid[i][j] = grid[i][j] ^ 1;
        }

        for(int j = 0; j < w; j++) {
            int l = j > 0 ? grid[i][j - 1] : -1;
            int r = j + 1 < w ? grid[i][j + 1] : -1;
            lr_states[i][j] = grid[i][j] == l || grid[i][j] == r;
        }
    }

    vector<vector<int>> dp(2, vector<int>(2, MAX));
    dp[0][0] = 0;
    dp[1][0] = 1; 
    for(int i = 1; i < h; i++) {
        vector<vector<int>> tmp(2, vector<int>(2, MAX));

        for(int j = 0; j < 8; j++) {
            vector<int> r1 = i == 1 ? vector<int>(w, - 1) : (j >> 2) & 1 ? flipped_grid[i - 2] : grid[i - 2];
            vector<int> r2 = (j >> 1) & 1 ? flipped_grid[i - 1] : grid[i - 1];
            vector<int> r3 = j & 1 ? flipped_grid[i] : grid[i];

            bool flag = true;
            for(int k = 0; k < w; k++) {
                if (!lr_states[i - 1][k] && r1[k] != r2[k] && r2[k] != r3[k]) {
                    flag = false;
                    break;
                }
            }

            if (i == h - 1) {
                for(int k = 0; k < w; k++) {
                    if (r2[k] != r3[k] && !lr_states[i][k]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                tmp[j & 1][(j >> 1) & 1] = min(tmp[j & 1][(j >> 1) & 1], dp[(j >> 1) & 1][(j >> 2) & 1] + (j & 1));
            }
        }

        dp = tmp;
    }

    int ans = MAX;
    ans = min(ans, min(min(dp[0][0], dp[0][1]), min(dp[1][0], dp[1][1])));
    ans = ans == MAX ? -1 : ans;

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}