#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjL(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        adjL[u].push_back(v);
    }

    queue<int> q;
    vector<bool> seen(n, false);
    q.push(0);
    int d = 1;

    while(q.size()) {
        int sz = q.size();

        while(sz--) {
            int u = q.front(); q.pop();
            for(int v : adjL[u]) {
                if (seen[v]) continue;
                if (v == 0) {
                    cout << d << endl;
                    return;
                }

                seen[v] = true;
                q.push(v);
            }
        }
        
        ++d;
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}