#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int t;
    cin >> t;

    while(t--) {
        ll n, x, k;
        cin >> n >> x >> k;

        auto count = [&](ll cur, ll d) -> ll {            
            ll l, r;
            l = r = cur;

            while(d) {
                l <<= 1;
                r = r << 1 | 1; 
                --d;

                if (l > n) return 0;
            }

            return min(r, n) - l + 1;
        };

        ll ans = count(x, k);
        for(; k > 1 && x > 1; k--) {
            ans += count(x ^ 1, k - 2);
            x >>= 1;
        }
        if (k == 1 && x > 1) ans++;

        cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}