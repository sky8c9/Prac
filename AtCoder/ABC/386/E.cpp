#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    ll sum = 0;
    vector<ll> a(n);
    for(ll& val : a) {
        cin >> val;
        sum ^= val;
    }

    auto compute = [&](auto compute, int curI, int r, ll curVal) -> void {
        if (r == 0) {
            ans = max(ans, curVal);
            return;
        }
 
        for(int i = curI; i < n; i++) {
            if (n - i < r) return;
            compute(compute, i + 1, r - 1, curVal ^ a[i]);
        }
    };

    if (k > n - k) compute(compute, 0, n - k, sum);
    else compute(compute, 0, k, 0);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}