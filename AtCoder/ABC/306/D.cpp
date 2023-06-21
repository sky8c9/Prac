#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    ll ans = 0;
    ll healthy = 0;
    ll unhealthy = 0;

    for(int i = 0; i < n; i++) {
        int state, val;
        cin >> state >> val;

        if (state) {
            unhealthy = max(unhealthy, healthy + val);
        } else {
            healthy = max(healthy, val + max(healthy, unhealthy));
        }

        ans = max(ans, max(unhealthy, healthy));
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}