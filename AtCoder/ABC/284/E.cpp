#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int ans = 0;
vector<int> seen;
vector<vector<int>> adjL;
void dfs(int u) {
    if (seen[u]) return;
    seen[u] = true;

    if (ans >= (int)1e6) return;
    ++ans;
    for(int v : adjL[u]) {
        if (seen[v]) continue;
        dfs(v);
    }

    seen[u] = false;
}

void task() {
    int n, m;
    cin >> n >> m;

    adjL.resize(n);
    seen.resize(2*1e5 + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    dfs(0);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}