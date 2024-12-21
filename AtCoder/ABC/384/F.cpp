#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MAX = 25;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    vector<ll> total(MAX + 1);
    for(int k = 0; k < MAX; k++) {
        int mod = 1 << k;
        vector<ll> cnt(mod);
        vector<ll> sum(mod);
        for(int i = 0; i < n; i++) {
            sum[a[i] % mod] += a[i];
            ++cnt[a[i] % mod];

            int ri = (mod - a[i] % mod) % mod;
            total[k] += sum[ri];
            total[k] += cnt[ri] * a[i];
        }
    }

    ll ans = 0;
    for(int i = 0; i < MAX; i++) {
        ans += (total[i] - total[i + 1]) >> i;
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}