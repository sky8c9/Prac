#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Component {
    vector<int> ids;
    int mask;

    Component() {
        ids = vector<int>();
        mask = 0;
    }
};

int count_1(int n) {
    int ans = 0;
    while(n) {
        n = n & (n - 1);
        ++ans;
    }
    return ans;
}

bool canAdd(int a, int b, int c) {
    return count_1(a) + count_1(b) == count_1(c);
}

void task() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjL(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;

        adjL[a].emplace_back(b, -c);
        adjL[b].emplace_back(a, c);
    }

    vector<Component> coms;
    vector<int> ranks(n, 0);
    vector<bool> seen(n, false);
    for(int i = 0; i < n; i++) {
        if (seen[i]) continue;

        coms.push_back(Component());
        int mn = 0;

        auto& comI = coms.back();
        auto dfs = [&] (auto dfs, int u) -> void {
            seen[u] = true;
            comI.ids.push_back(u);
            mn = min(mn, ranks[u]);

            for(auto [v, c] : adjL[u]) {
                if (seen[v]) continue;
                ranks[v] = ranks[u] + c;
                dfs(dfs, v);
            }
        };

        dfs(dfs, i);

        for(int ele : comI.ids) {
            ranks[ele] -= mn;
            comI.mask |= 1<<ranks[ele]; 
        }
    }

    vector<int> ans(n, -1);
    int sz = 1<<n;
    for(int i = 0; i < coms.size(); i++) {
        vector<bool> dp(sz, false);
        dp[0] = true;

        for(int j = 0; j < coms.size(); j++) {
            if (i == j) continue;

            for(int s = sz - 1; s >= 0; s--) {
                if (dp[s]) {
                    int cur = coms[j].mask;

                    while(cur < sz) {
                        if (canAdd(s, cur, s|cur)) {
                            dp[s|cur] = true;
                        }
                        cur <<= 1;
                    }
                }
            }
        }

        int cur = coms[i].mask;
        int shift = 0;
        vector<int> shifts;
        while(cur < sz) {
            if (dp[(sz - 1) ^ cur]) {
                shifts.push_back(shift);
            }
            ++shift;
            cur <<= 1;
        }

        if (shifts.size() == 1) {
            for(int ele : coms[i].ids) {
                ans[ele] = shifts[0] + ranks[ele] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}