#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, q;
    cin >> n >> q;

    vector<int> r(n);
    for(int& val : r) cin >> val;

    sort(r.begin(), r.end());
    vector<ll> sum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + r[i];
    }

    while(q--) {
        ll x;
        cin >> x;

        auto itr = upper_bound(sum.begin(), sum.end(), x);
        int cnt = itr - sum.begin() - 1;
        cout << max(0, cnt) << endl;
    }
    
}

int main() {
    task();
    return 0;
}