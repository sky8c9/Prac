#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        auto itr = lower_bound(a.begin(), a.end(), 2*a[i]);
        if (itr == a.end()) continue;
        ans += n - (itr - a.begin());
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}