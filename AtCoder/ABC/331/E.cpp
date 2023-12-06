#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using ll = long long;
using namespace std;

void task() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n);
    for(int& val : a) cin >> val;

    vector<pair<int, int>> b(m);
    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        b.emplace_back(val, i);
    }

    sort(b.rbegin(), b.rend());
    vector<set<int>> mp(n);
    for(int i = 0; i < l; i++) {
        int c, d;
        cin >> c >> d;
        --c; --d;
        mp[c].insert(d);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = 0;
        while(j < m && mp[i].count(b[j].second)) ++j;
        if (j < m) ans = max(ans, a[i] + b[j].first);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}