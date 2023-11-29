#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

void task() {
    ll d;
    cin >> d;

    ll ans = 1e18;
    for(int x = 0; x <= 2 * 1e6; x++) {
        ll x2 = (ll) x * x;
        ll y2 = d - x2;
        if (y2 < 0) ans = min(ans, -y2);
        else {
            ll y = (ll) sqrt(y2);
            ans = min(ans, abs(x2 + y * y - d));
            ans = min(ans, abs(x2 + (y + 1) * (y + 1) - d));
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}