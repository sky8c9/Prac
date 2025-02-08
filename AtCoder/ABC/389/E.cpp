#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void task() {
    ll n, m;
    cin >> n >> m;

    ll total = 0;
    ll cnt = 0;
    vector<ll> p(n);
    for(ll& val : p) cin >> val;

    auto checked = [&](ll x) -> bool {
        total = 0;
        cnt = 0;

        for(ll i = 0; i < n; i++) {
            ll k = ((x / p[i]) + 1) / 2;
            if (k != 0 && m / k / k < p[i]) return false;

            total += k * k * p[i];
            cnt += k;
            if (total > m) return false;
        }

        return total <= m;
    };

    ll lo = 1;
    ll hi = m;
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2 + 1;
        if (checked(mid)) lo = mid;
        else hi = mid - 1;
    }

    checked(lo);
    cnt += (m - total) / (lo + 1);
    cout << cnt << endl;
}

int main() {
    task();
    return 0;
}