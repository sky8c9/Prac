#include <iostream>
#include <set>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> p;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (p.count({u, v}) || p.count({v, u}) || u == v) ++ans;
        else {
            p.insert({u, v});
            p.insert({v, u});
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}