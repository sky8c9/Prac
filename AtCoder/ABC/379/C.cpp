#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for(int i = 0; i < m; i++) cin >> x[i];

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    vector<pair<int, ll>> p;
    for(int i = 0; i < m; i++) p.emplace_back(x[i], a[i]);

    p.emplace_back(n + 1, 0);
    sort(p.begin(), p.end());

    ll pos = 1;
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        if (p[i].first > pos) {
            cout << -1 << endl;
            return;
        }

        int diff = p[i + 1].first - p[i].first;
        ans += (p[i].second - 1 + p[i].second - diff) * diff / 2;

        pos = p[i].second + p[i].first;
        p[i + 1].second += p[i].second - diff;
    }
  
    if (p[m].second == 0) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    task();
    return 0;
}