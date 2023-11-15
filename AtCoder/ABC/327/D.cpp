#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, vector<int>& seen, vector<vector<int>>& adjL, int c) {
    seen[u] = c;
    for(int v : adjL[u]) {
        if (seen[v] == -1) {
            if (!dfs(v, seen, adjL, c ^ 1)) return false;
        } else if (seen[v] == seen[u]) {
            return false;
        }
    }
    return true;
}

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    vector<vector<int>> adjL(n + 1);
    for(int i = 0; i < m; i++) cin >> a[i]; 
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < m; i++) {
        adjL[a[i]].push_back(b[i]);
        adjL[b[i]].push_back(a[i]);
    }

    vector<int> seen(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if (seen[i] >= 0) continue;
        if(!dfs(i, seen, adjL, 0)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}