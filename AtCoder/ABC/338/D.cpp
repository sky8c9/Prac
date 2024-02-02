#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for(int&val : x) cin >> val;

    vector<ll> freq(n + 1, 0);
    for(int i = 0; i < m - 1; i++) {
        int l = min(x[i], x[i + 1]);
        int r = max(x[i], x[i + 1]);

        int dist1 = r - l;
        int dist2 = n - dist1;

        freq[l] += dist2;
        freq[r] += -dist2;

        freq[1] += dist1;
        freq[l] -= dist1;

        freq[r] += dist1;
    }

    for(int i = 1; i <= n; i++) {
        freq[i] += freq[i - 1];
    }

    ll ans = 1e18;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, freq[i]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}