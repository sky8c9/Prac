
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll n, d, p;
    cin >> n >> d >> p;

    ll ans = 0;
    vector<ll> f(n);
    for(ll& val : f) cin >> val;
    sort(f.rbegin(), f.rend());

    for(int i = 0; i < n;) {
        ll total = 0;
        for(int j = 0; j < d && i + j < n; j++) {
            total += f[i + j];
        }
        ans += min(total, p);
        i += d;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}