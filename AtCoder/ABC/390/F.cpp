#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& val : a) cin >> val;

    vector<vector<int>> pos(n + 2);
    for(int val = 1; val <= n + 1; val++) pos[val].push_back(0);
    for(int i = 0; i < n; i++) pos[a[i]].push_back(i + 1);

    auto compute = [&] (vector<int>& indices) -> ll {
        ll res = (ll) n * (n + 1) / 2;
        int m = indices.size();

        for(int i = 1, prev = 0; i <= m; i++) {
            int cnt = (i == m ? n + 1 : indices[i]) - prev - 1;
            ll excl = (ll) cnt * (cnt + 1) / 2;

            res -= excl;
            prev = indices[i];
        }

        return res;
    };

    ll ans = 0;
    for(int val = 1; val <= n; val++) {
        vector<int> app;

        for(int i : pos[val]) app.push_back(i);
        for(int i : pos[val + 1]) app.push_back(i);
        sort(app.begin(), app.end());

        ans += compute(app) - compute(pos[val + 1]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}