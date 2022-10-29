#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const double MAX = 1e18;

double dist(int i, int j, int booster, vector<pair<int, int>>& points) {
    double diffX = points[i].first - points[j].first;
    double diffY = points[i].second - points[j].second;
    return sqrt(diffX * diffX + diffY * diffY) / booster ;
}

void task() {
    int n,m;
    cin >> n >> m;

    vector<pair<int, int>> points;
    points.emplace_back(0, 0);
    for(int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    vector<vector<double>> dp(n + m + 1, vector<double>(1 << (n + m + 1), MAX));
    for(int i = 0; i < n + m + 1; i++) dp[i][1 << i] = dist(i,0,1,points);
    for(int s = 0; s < (1 << (n + m + 1)); s++) {
        int booster = 1;
        for(int i = 0; i < m; i++) {
            if ((s >> (i + n + 1)) & 1) booster *= 2;
        }

        for(int i = 0; i < n + m + 1; i++) {      
            if ((s >> i) & 1) continue;
            for(int j = 0; j < n + m + 1; j++) {
                if ((s >> j) & 1) {
                    dp[i][s | (1 << i)] = min(dp[i][s | (1 << i)], dp[j][s] + dist(i, j, booster, points));
                }  
            }
        }
    }

    double ans = MAX;
    int mask = (1 << (n + 1)) - 1;
    for(int i = 0; i < (1 << m); i++) {
        ans = min(ans, dp[0][(i << (n + 1)) | mask]);
    }

    printf("%.8f\n", ans);
}

int main() {
    task();
    return 0;
}