#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adjL(n);
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        --a; --b;
        adjL[a].emplace_back(b, c);
        adjL[b].emplace_back(a, c);
        ans += 2*c;
    }

    auto dfs = [&](auto dfs, int u, int p, ll d) -> pair<int, ll> {
        pair<int, ll> mx{u, d};

        for(auto [v, l] : adjL[u]) {
            if (v == p) continue;
            pair<int, ll> res = dfs(dfs, v, u, d + l);
            if (res.second > mx.second) {
                mx.second = res.second;
                mx.first = res.first;
            }
        }

        return mx;
    };

    int from = dfs(dfs, 0, -1, 0).first;
    ll rm = dfs(dfs, from, -1, 0).second;

    cout << ans - rm << endl;
}

int main() {
    task();
    return 0;
}