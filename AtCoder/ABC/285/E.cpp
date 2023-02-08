#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> prod(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            prod[i] += a[min(j, i - j)];
        }
    }

    vector<ll> dp(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + prod[i - j]);
        }
    }

    cout << dp[n] << endl;
}

int main() {
    task();
    return 0;
}
