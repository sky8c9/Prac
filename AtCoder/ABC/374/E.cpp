#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;

        if (a * q >= b * p) v.push_back({a, p, b, q});
        else v.push_back({b, q, a, p});
    }

    int lo = 0;
    int hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2 + 1;
        ll total = x;
        bool flag = true;

        for(int i = 0; i < n; i++) {
            ll mn = 1e18;

            for(int j = 0; j < v[i][0]; j++) {
                int r = max(0, mid - (j * v[i][2]));
                int cnt = (r + v[i][0] - 1) / v[i][0];

                ll cost = (ll) cnt * v[i][1] + j * v[i][3];
                mn = min(mn, cost);
            }

            total -= mn;
            if (total < 0) {
                flag = false;
                break;
            }
        }

        if (flag) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << endl;
}

int main() {
    task();
    return 0;
}