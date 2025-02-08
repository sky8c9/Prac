#include <iostream>

using namespace std;
using ll = long long;

void task() {
    int r;
    cin >> r;

    auto checked = [&](ll x, ll y) {
        return (2 * x + 1) * (2 * x + 1) + (2 * y + 1) * (2 * y + 1) <= (ll) 4 * r * r;
    };

    ll ans = 0;
    for(int i = 1; i < r; i++) {
        int lo = 0;
        int hi = r;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2 + 1;
            if (checked(mid, i)) lo = mid;
            else hi = mid - 1;
        }

        ans += lo;
    }

    ans *= 4;
    ans += 4 * (r - 1) + 1;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}