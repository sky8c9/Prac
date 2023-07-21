#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs (int u, vector<vector<int>>& adjL, vector<int>& dist) {
    for(int v : adjL[u]) {
        dist[v] = max(dist[v], dist[u] - 1);
        dfs(v, adjL, dist);
    }
}

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjL(n);
    vector<int> dist(n, -1);
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        --p;

        adjL[p].push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;

        dist[x] = max(dist[x], y);
    }

    dfs(0, adjL, dist);
    
    int ans = n;
    for(int i = 0; i < n; i++) {
        if (dist[i] < 0) --ans;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}