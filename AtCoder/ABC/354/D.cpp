#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll SHIFT = 1e9;

void task() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    --c; --d;

    a += SHIFT; b += SHIFT; c += SHIFT; d += SHIFT;
    vector<ll> sO {1, 2, 1, 0};
    vector<ll> sE {2, 1, 0, 1};

    ll rowO, rowE;
    rowO = rowE = (c - a + 1) / 4 * 4;
    for(int i = 0; i < (c - a + 1) % 4; i++) rowO += sO[(a + i) % 4];
    for(int i = 0; i < (c - a + 1) % 4; i++) rowE += sE[(a + i) % 4];

    ll cntO = (d - b) / 2 + ((d % 2 != 0 || b % 2 != 0) ? 1 : 0);
    ll cntE = (d - b + 1) - cntO;
    
    ll ans = cntO * rowO + cntE * rowE;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}