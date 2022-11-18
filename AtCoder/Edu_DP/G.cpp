#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void task() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adjL(n + 1);
    vector<int> deg(n + 1);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        ++deg[v];
    }

    vector<int> dp(n + 1);
    int ans = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adjL[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            ans = max(ans, dp[v]);
            if (--deg[v] == 0) q.push(v);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}