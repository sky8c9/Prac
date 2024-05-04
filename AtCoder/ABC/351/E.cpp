#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll compute(vector<ll>& v) {
    int n = v.size();
    sort(v.begin(), v.end());

    ll ans = 0;
    ll total = 0;
    for(int i = 0; i < n; i++) {
        ans += i * v[i] - total;
        total += v[i];
    }

    return ans;
}

void task() {
    int n;
    cin >> n;

    vector<vector<ll>> pX(2);
    vector<vector<ll>> pY(2);
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        pX[x + y & 1].emplace_back(x + y);
        pY[x + y & 1].emplace_back(x - y);
    }

    ll ans = 0;
    ans += compute(pX[0]) + compute(pX[1]);
    ans += compute(pY[0]) + compute(pY[1]);

    cout << ans / 2 << endl;
}

int main() {
    task();
    return 0;
}