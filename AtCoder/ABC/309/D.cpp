#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int findLongest(vector<vector<int>>& adjL, int start) {
    queue<int> q;
    set<int> seen;
    int len = 0;

    q.push(start);
    seen.insert(start);
    while(q.size()) {
        int sz = q.size();
        
        for(int i = 0; i < sz; i++) {
            int u = q.front(); q.pop();
            for(int v : adjL[u]) {
                if (seen.count(v)) continue;
                seen.insert(v);
                q.push(v);
            }
        }

        ++len;
    }

    return len - 1;
}

void task() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    vector<vector<int>> adjL(n1 + n2);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        --a; --b;
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    int ans = findLongest(adjL, 0) + findLongest(adjL, n1 + n2 - 1) + 1;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}