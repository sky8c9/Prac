#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll MAX = 2 * 1e5;

struct Bit {
    vector<ll> bit;
    ll size;

    Bit(ll n) {
        size = n + 1;
        bit.resize(size);
    }

    void update(ll i, ll val) {
        while(i <= size) {
            bit[i] += val;
            bit[i] %= MOD;
            i += i & -i;
        }
    }

    ll sum(ll i) {
        ll sum = 0;

        while(i > 0) {
            sum += bit[i];
            sum %= MOD;
            i -= i & -i;
        }

        return sum;
    }
};

ll pow_mod(ll x, ll y) {
    ll ans = 1;
    x %= MOD;

    while(y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }

        x *= x;
        x %= MOD;
        y >>= 1;
    }

    return ans;
}

void task() {
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    Bit bit_smaller(MAX + 1);
    Bit bit_greater(MAX + 1);
    ll ans = 0;

    for(ll i = 1; i <= n; i++) {
        ll val;
        cin >> val;

        ans += val + (bit_smaller.sum(val) * val + bit_greater.sum(MAX) - bit_greater.sum(val)) * 2;
        ans %= MOD;

        bit_smaller.update(val, 1);
        bit_greater.update(val, val);

        cout << ans * pow_mod(i * i, MOD - 2) % MOD << endl;
    }    
}

int main() {
    task();
    return 0;
}
