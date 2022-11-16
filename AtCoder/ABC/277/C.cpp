#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

void task() {
    int n;
    cin >> n;

    unordered_map<int, vector<int>> edges;
    while(n--) {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    unordered_set<int> seen;
    queue<int>q; q.push(1);
    seen.insert(1);
    int ans = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : edges[u]) {
            if (seen.count(v)) continue;
            ans = max(ans, v);
            seen.insert(v);
            q.push(v);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}