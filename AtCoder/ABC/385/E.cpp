#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<vector<int>> adjL(n);
    vector<int> deg(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        adjL[u].push_back(v);
        adjL[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    int ans = n;
    for(int u = 0; u < n; u++) {
        vector<int> sz;
        for(int v : adjL[u]) sz.push_back(deg[v]);
        sort(sz.rbegin(), sz.rend());
        
        for(int i = 1; i <= sz.size(); i++) {
            int used = 1 + sz[i - 1] * i;
            int del = n - used;
            ans = min(ans, del);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}