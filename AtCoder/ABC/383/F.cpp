#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Node {
    int p, u, c;
    Node(int p, int u, int c) : p(p), u(u), c(c) {}
};

bool cmp(Node a, Node b) {
    return a.c > b.c;
}

void task() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<Node> t;
    for(int i = 0; i < n; i++) {
        int p, u, c;
        cin >> p >> u >> c;
        t.emplace_back(p, u, c);
    }

    sort(t.begin(), t.end(), cmp);

    vector<vector<ll>> dp(x + 1, vector<ll>(2, 0));
    dp[0][0] = 0;
    dp[t[0].p][1] = t[0].u + k;
    for(int i = 1; i < n; i++) {
        if (t[i].c != t[i - 1].c) {
            for(int j = 0; j <= x; j++) {
                dp[j][0] = max(dp[j][0], dp[j][1]);
            }
        }

        vector<vector<ll>> tmp = dp;
        for(int j = 0; j <= x - t[i].p; j++) {
            int nj = j + t[i].p;
            tmp[nj][1] = max(tmp[nj][1], max(dp[j][1] + t[i].u, dp[j][0] + t[i].u + k));
        }
        dp = tmp;
    }

    ll ans = 0;
    for(int i = 0; i <= x; i++) {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}