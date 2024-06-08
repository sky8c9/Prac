#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        p.emplace_back(l, 0);
        p.emplace_back(r, 1);
    }

    sort(p.begin(), p.end());
    
    int cnt1 = 0;
    ll excluded = 0;
    for(int i = 0; i < 2*n; i++) {
        if (p[i].second) ++cnt1;
        else excluded += cnt1;
    }

    ll ans = (ll) n * (n - 1) / 2 - excluded;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}