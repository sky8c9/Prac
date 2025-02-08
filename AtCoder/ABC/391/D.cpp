#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void task() {
    int n, w;
    cin >> n >> w;

    map<int, vector<pair<int, int>>> m;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[x].emplace_back(y, i + 1);
    }

    for(auto[k, v] : m) sort(m[k].rbegin(), m[k].rend());

    vector<int> d(n + 1);
    while(true) {
        int mx = 0;
        vector<int> items;
        for(auto&[k, v] : m) {
            if (m[k].size() == 0) continue;
            else {
                mx = max(mx, v.back().first);
                items.push_back(v.back().second);
                v.pop_back();
            }
        }

        if (items.size() < w) mx = MAX;
        if (items.size() == 0) break;
        for(int item : items) d[item] = mx;
    }

    int q;
    cin >> q;
    while(q--) {
        int t, a;
        cin >> t >> a;

        if (t + 1 > d[a]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}

int main() {
    task();
    return 0;
}