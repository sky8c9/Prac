#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;
double dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void task() {
    ll n, k, sx, sy;
    cin >> n >> k >> sx >> sy;

    vector<pair<ll, ll>> pos;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }

    vector<double> prefS(n, 0);
    vector<double> cost(n, 0);
    vector<double> dp(n, 1e18);
    for(int i = 0; i < n - 1; i++) {
        double dir = dist(pos[i].first, pos[i].second, pos[i + 1].first, pos[i + 1].second);
        double indir = dist(pos[i].first, pos[i].second, sx, sy) + dist(sx, sy, pos[i + 1].first, pos[i + 1].second);
        prefS[i + 1] = prefS[i] + dir;
        cost[i] = indir - prefS[i + 1];
    }

    deque<double> dq;
    dp[0] = 0;
    dq.push_back(0);
    for(int i = 1; i < n; i++) {
        if (i < k) {
            dp[i] = prefS[i];
        } else {
            while(!dq.empty() && dq.front() < i - k) dq.pop_front();
            dp[i] = dp[dq.front()] + cost[dq.front()] + prefS[i];
        }

        if (i == n - 1) break;
        while(!dq.empty() && (dp[dq.back()] + cost[dq.back()]) >= (dp[i] + cost[i])) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    double ans = dp[n - 1];
    ans += dist(pos[0].first, pos[0].second, sx, sy) + dist(pos[n - 1].first, pos[n - 1].second, sx, sy);

    printf("%.10f\n", ans);
}

int main() {
    task();
    return 0;
}