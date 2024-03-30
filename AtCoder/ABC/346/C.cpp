#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

void task() {
    ll n, k;
    cin >> n >> k;

    ll sumK = k * (k + 1) / 2;

    set<ll> seen;
    for(int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        if (seen.count(val)) continue;
        
        seen.insert(val);
        if (val <= k) sumK -= val;
    }

    cout << sumK << endl;
}

int main() {
    task();
    return 0;
}