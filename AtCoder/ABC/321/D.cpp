#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n);
    vector<int> b(m);
    for(int& val : a) cin >> val;
    for(int& val : b) cin >> val;

    sort(b.begin(), b.end());
    vector<ll> prefSb(m + 1);
    for(int i = 0; i < m; i++) {
        prefSb[i + 1] = prefSb[i] + b[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int r = p - a[i];
        auto itr = lower_bound(b.begin(), b.end(), r);

        int idx = itr - b.begin();
        ans += ll (a[i]) * idx + prefSb[idx];
        ans += ll (b.size() - idx) * p;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}