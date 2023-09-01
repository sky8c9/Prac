#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int u, vector<vector<int>>& adjL, vector<bool>& seen) {
    seen[u] = true;
    for(int v : adjL[u]) {
        if (seen[v]) continue;
        dfs(v, adjL, seen);
    }
    if (u != 1) cout << u << " ";
}

void task() {
    int n;
    cin >> n;

    vector<vector<int>> adjL(n + 1);
    vector<bool> seen(n + 1);
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;

        while(c--) {
            int p;
            cin >> p;
            adjL[i].push_back(p);
        }
    }

    dfs(1, adjL, seen);
    cout << endl;
}

int main() {
    task();
    return 0;
}