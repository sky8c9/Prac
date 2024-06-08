#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 998244353;

void task() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    for(int i = 0; i < 60; i++) {
        if (m >> i & 1) {
            ll sz = 1ll << i;
            ll q = n / sz;
            ll r = n % sz;

            ans += (q / 2) * sz;
            ans %= MOD;

            ans += q % 2 ? r + 1 : 0;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}