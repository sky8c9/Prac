#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll l, r;
    cin >> l >> r;

    auto powll = [&](ll a, ll b) -> ll {
        ll res = 1;

        for(int i = 0; i < b; i++) {
            res *= a;
        }

        return res;
    };

    auto countSmallerLen = [&](int s, int len) -> ll {
        ll res = 0;

        for(int d = s; d > 0; d--) {
            for(int i = len; i > 0; i--) {
                res += powll(d, i);
            }
        }

        return res;
    };

    auto count = [&](ll n) -> ll {
        if (n < 10) return 0;

        string s = to_string(n);
        int len = s.size();
        int d0 = s[0] - '0';
        ll res = 0;
        for(int i = 1; i <= len; i++) {
            if (i == len) {
                ++res;
                break;
            }

            int di = s[i] - '0';
            res += (ll) min(d0, di) * powll(d0, len - 1 - i);
            if (di >= d0) break;
        }

        for(int i = 1; i < d0; i++) {
            res += powll(i, len - 1);
        }

        res += countSmallerLen(9, len - 2);
        return res;
    };

    ll ans = count(r) - count(l - 1);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}