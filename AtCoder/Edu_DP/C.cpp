#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9 + 8;

void task() {
    int n;
    cin >> n;

    vector<vector<int>> abc(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
    }

    vector<int> dp(3, 0);
    for(int i = 0; i < n; i++) {
        vector<int> tmp(3);
        tmp[0] = max(dp[1], dp[2]) + abc[i][0];
        tmp[1] = max(dp[0], dp[2]) + abc[i][1];
        tmp[2] = max(dp[0], dp[1]) + abc[i][2];
        dp = tmp;
    }

    cout << max(max(dp[0],dp[1]), dp[2]) << endl;
}

int main() {
    task();
    return 0;
}