#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll& val : a) cin >> val;

    vector<vector<ll>> groups;
    vector<ll> vals;
    auto dfs = [&](auto dfs, int i) -> void {
        if (i == n) {
            ll res = 0;

            for(vector<ll> group : groups) {
                ll total = accumulate(group.begin(), group.end(), 0LL);
                res ^= total;
            }

            vals.push_back(res);
        } else {
            groups.push_back({a[i]});
            dfs(dfs, i + 1);
            groups.pop_back();

            for(int j = 0; j < groups.size(); j++) {
                groups[j].push_back(a[i]);
                dfs(dfs, i + 1);
                groups[j].pop_back();
            }
        }
    };

    dfs(dfs, 0);

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    cout << vals.size() << endl;

}

int main() {
    task();
    return 0;
}