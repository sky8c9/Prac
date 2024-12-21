#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    ll s;
    cin >> n >> s;

    ll total = 0;
    vector<int> a(2*n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
        total += a[i];
    }

    vector<ll> prefS(2*n + 1);
    for(int i = 0; i < 2*n; i++) {
        prefS[i + 1] = prefS[i] + a[i];
    }

    ll r = s % total;
    if (r == 0) {
        cout << "Yes" << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        ll val = r + prefS[i - 1];
        auto itr = lower_bound(prefS.begin() + i, prefS.end(), val);
        if (itr != prefS.end() && *itr - val == 0) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;

}

int main() {
    task();
    return 0;
}