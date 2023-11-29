#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll compute(vector<int>& v, int len) {
    int r = v.back() - v[0] - len;
    int d = 1;
    int lo = 0;
    int hi = v.size() - 1;

    ll cost = 0;
    while(lo < hi) {
        if (r <= 0) break;
        int dL = v[lo + 1] - v[lo];
        int dR = v[hi] - v[hi - 1];
        int delta = min(dL + dR, r);

        r -= delta;
        cost += (ll) d * delta;
        ++d;

        ++lo;
        --hi;
    }
    
    return cost;
}

void task() {
    ll n, k;
    cin >> n >> k;

    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int lo = 0;
    int hi = max(x.back() - x[0], y.back() - y[0]);
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        ll costX = compute(x, mid);
        ll costY = compute(y, mid);

        if (costX + costY <= k) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
}

int main() {
    task();
    return 0;
}