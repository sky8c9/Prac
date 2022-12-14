#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

void task() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    multiset<int> mmn;
    multiset<int> mmx;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        mmn.insert(a[i]);

        if (i >= m) {
            if (mmx.count(a[i - m])) {
                mmx.erase(mmx.find(a[i - m]));
                sum -= a[i - m];
            } else mmn.erase(mmn.find(a[i - m]));
        }

        if (!mmx.empty()) {
            auto mmx_last_itr = prev(mmx.end());
            sum -= *mmx_last_itr;
            mmn.insert(*mmx_last_itr);
            mmx.erase(mmx_last_itr);
        }

        while(!mmn.empty() && mmx.size() < k) {
            sum += *mmn.begin();
            mmx.insert(*mmn.begin());
            mmn.erase(mmn.begin());
        }

        if (i >= m - 1) cout << sum << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}