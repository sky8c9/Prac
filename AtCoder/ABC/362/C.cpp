#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> lr;
    vector<ll> ans;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        lr.emplace_back(l, r);
        ans.push_back(l);
        sum += l;
    }

    ll lo, hi;
    lo = hi = 0;
    for(int i = 0; i < n; i++) {
        auto[l, r] = lr[i];
        lo = lo + l;
        hi = hi + r;
    }

    if (hi < 0 || lo > 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i = 0; i < n; i++) {
            ll diff = lr[i].second - lr[i].first;
            ll mn = min(-sum, diff);

            sum += mn;
            ans[i] += mn;
            if (sum == 0) break;
        }
        
        for(ll& val : ans) cout << val << " ";
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}