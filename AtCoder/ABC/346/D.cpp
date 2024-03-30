#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

void task() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> c(n);
    for(int&val  : c) cin >> val;

    vector<ll> ending0(n + 1);
    vector<ll> ending1(n + 1);
    for(int i = 0; i < n; i++) {
        ending0[i + 1] = ending1[i] + (s[i] == '1' ? c[i] : 0);
        ending1[i + 1] = ending0[i] + (s[i] == '0' ? c[i] : 0);
    }

    vector<ll> starting0(n + 1);
    vector<ll> starting1(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        starting0[i] = starting1[i + 1] + (s[i] == '1' ? c[i] : 0);
        starting1[i] = starting0[i + 1] + (s[i] == '0' ? c[i] : 0);
    }

    ll ans = MAX;
    for(int i = 0; i < n - 1; i++) {
        ll cost0 = s[i] == '0' ? 0 : c[i];
        cost0 += s[i + 1] == '0' ? 0 : c[i + 1];

        ll cost1 = s[i] == '1' ? 0 : c[i];
        cost1 += s[i + 1] == '1' ? 0 : c[i + 1];

        cost0 += ending1[i] + starting1[i + 2];
        cost1 += ending0[i] + starting0[i + 2];
        ans = min(ans, min(cost0, cost1));
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}