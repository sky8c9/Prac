#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<ll> prefS(n + 1);
    for(int i = 1; i <= n; i++) {
        prefS[i] = prefS[i - 1] + (s[i - 1] == 'x' ? 1 : 0);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll l = i;
        ll r = n * m - 1;
        
        while (l < r) {
            ll mid = l + (r - l) / 2 + 1;
            ll cntX = (mid / n) * prefS[n] + prefS[mid % n + 1] - prefS[i];

            if (cntX <= k) l = mid;
            else r = mid - 1;
        }

        ans = max(ans, l - i + 1);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}