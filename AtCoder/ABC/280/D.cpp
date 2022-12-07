#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll k;
    cin >> k;

    unordered_map<ll, int> factors;
    while (k % 2 == 0) {
        factors[2]++;
        k /= 2;
    }

    for (ll i = 3; (i * i) <= k; i += 2) {
        while (k % i == 0) {
            factors[i]++;
            k /= i;
        }
    }

    if (k > 2) factors[k] = 1;

    ll mx = 0;
    for(auto[p, f] : factors) {
        for(ll cur=p; f > 0; cur+=p) {
            mx = max(mx, cur);
            ll tmp = cur;
            while(tmp % p == 0) {
                tmp /= p;
                --f;
            }
        }
    }

    cout << mx << endl;
}

int main() {
    task();
    return 0;
}