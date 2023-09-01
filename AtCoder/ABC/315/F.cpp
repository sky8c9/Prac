#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 1e9;
void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> xy;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xy.emplace_back(x, y);
    }

    auto dist = [&] (int i, int j) {
        int dx = xy[i].first - xy[j].first;
        int dy = xy[i].second - xy[j].second;
        return sqrt(dx * dx + dy * dy);
    };

    vector<vector<double>> dp(n, vector<double>(30, MAX));
    dp[0][0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < min(i, 30); j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + dist(i - k - 1, i));
            }
        }
    }

    double ans = dp[n - 1][0];
    int penalty = 1;
    for(int i = 1; i < 30; i++) {
        ans = min(ans, dp[n - 1][i] + penalty);
        penalty <<= 1;
    }

    printf("%.8f\n", ans);
}

int main() {
    task();
    return 0;
}