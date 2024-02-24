#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
const int MIN = -1e9;

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjL(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    vector<int> w(n);
    vector<int> a(n);
    for(int&val : w) cin >> val;
    for(int&val : a) cin >> val;

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int a, int b){return w[a] < w[b];});

    vector<int> dp(n, 0);
    for(int u : indices) {
        vector<int> dp2(w[u], MIN);
        dp2[0] = 0;
        int mx = 0;

        for(int v : adjL[u]) {
            if (w[v] >= w[u]) continue;
            for(int i = w[u] - 1; i >= 0; i--) {
                if (w[v] + i >= w[u] || dp2[i] == MIN) continue;
                dp2[w[v] + i] = max(dp2[w[v] + i], dp2[i] + dp[v]);
                mx = max(mx, dp2[w[v] + i]);
            }
        } 

        dp[u] = 1 + mx;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (ll) dp[i] * a[i];
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}