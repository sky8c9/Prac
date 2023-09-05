#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjL(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;

        adjL[a].emplace_back(b, c);
        adjL[b].emplace_back(a, c);
    }

    vector<bool> seen(n, false);
    int ans = 0;
    auto dfs = [&](auto dfs, int u, int val)-> void {
        seen[u] = true;
        for(auto[v, c] : adjL[u]) {
            if (seen[v]) continue;
            dfs(dfs, v, val + c);
        }
        seen[u] = false;
        ans = max(ans, val);
    };

    for(int i = 0; i < n; i++) {
        dfs(dfs, i, 0);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}