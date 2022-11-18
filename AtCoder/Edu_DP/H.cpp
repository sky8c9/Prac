#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;
void task() {
    int h,w;
    cin >> h >> w;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];
    
    vector<int> dp(w + 1);
    dp[1] = 1;
    for(int i = 0; i < h; i++) {
        vector<int> tmp(w + 1);
        for(int j = 1; j <= w; j++) {
            if (grid[i][j-1] == '#') tmp[j] = 0;
            else {
                tmp[j] = tmp[j - 1];
                tmp[j] = (tmp[j] + dp[j]) % MOD;
            }
        }
        dp = tmp;
    }

    cout << dp[w] << endl;
}

int main() {
    task();
    return 0;
}