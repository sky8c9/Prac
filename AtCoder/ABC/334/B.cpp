#include <iostream>

using namespace std;
using ll = long long;

ll compute(ll lo, ll hi, ll m) {
    ll rm = (hi - lo) % m;
    if (rm) return lo + m - rm;
    return lo;
}

void task() {
    ll a, m, l , r;
    cin >> a >> m >> l >> r;

    ll ans = 0;
    if (a < l) {
        ans = (r - a) / m - (l - a) / m;
        ans += (l - a) % m == 0; 
    } else if (a > r) {
        ans = (a - l) / m - (a - r) / m;
        ans += (a - r) % m == 0;
    } else {
        ans = (a - l) / m + (r - a) / m + 1;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}