#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long;

void task() {
    int h, w, m;
    cin >> h >> w >> m;

    map<int, ll> ans;
    set<int> seenR;
    set<int> seenC;

    vector<vector<int>> ops(m);
    for(int i = 0; i < m; i++) {
        int t, a, x;
        cin >> t >> a >> x;

        ops[i].push_back(t);
        ops[i].push_back(a);
        ops[i].push_back(x);
    }

    for(int i = m - 1; i >= 0; i--) {
        if (ops[i][0] == 1) {
            if (seenR.count(ops[i][1])) continue;
            ans[ops[i][2]] += w - seenC.size();
            seenR.insert(ops[i][1]);
        } else {
            if (seenC.count(ops[i][1])) continue;
            ans[ops[i][2]] += h - seenR.size();
            seenC.insert(ops[i][1]);
        }
    }

    ll zeros = (ll) h * w;
    for(auto[k, v] : ans) {
        if (v) zeros -= v;
    }

    ans[0] += zeros;
    int count = 0;
    for(auto[k, v] : ans) {
        if (v) ++count;
    }

    cout << count << endl;
    for(auto[k, v] : ans) {
        if (v) cout << k << " " << v << endl;
    }
}

int main() {
    task();
    return 0;
}