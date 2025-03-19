#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<vector<int>> adjL(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        --a; --b;
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    int ans = 1;
    auto dfs = [&](auto dfs, int u, int p) -> int {
        vector<int> w;

        for(int v : adjL[u]) {
            if (v == p) continue;
            w.push_back(dfs(dfs, v, u));
        }

        sort(w.rbegin(), w.rend());
        
        if (w.size() >= 3) {
            if (w.size() >= 4) ans = max(ans, w[0] + w[1] + w[2] + w[3] + 1);
            if (p != -1) ans = max(ans, w[0] + w[1] + w[2] + 2);
            return w[0] + w[1] + w[2] + 1;
        } else return 1;
    };

    dfs(dfs, 0, -1);

    ans = ans == 1 ? -1 : ans;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}