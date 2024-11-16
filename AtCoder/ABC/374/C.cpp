#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<ll> k(n);
    ll sum = 0;
    for(ll& val : k) {
        cin >> val;
        sum += val;
    }

    ll mn = 1e9;
    for(int i = 0; i < (1 << n) - 1; i++){
        ll cur = 0;
        for(int j = 0; j < n; j++) {
            if (i >> j & 1) {
                cur += k[j];
            }
        }

        mn = min(mn, max(cur, sum - cur));
    }

    cout << mn << endl;
}

int main() {
    task();
    return 0;
}