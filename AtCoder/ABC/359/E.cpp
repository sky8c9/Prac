#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAX = 2e9;
void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> stk;
    vector<ll> dp(n + 1);
    stk.emplace_back(MAX, 0);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;

        while(val > stk.back().first) {
            stk.pop_back();
        }

        dp[i] = dp[stk.back().second] + (ll) val * (i - stk.back().second);
        stk.emplace_back(val, i);
    }

    for(int i = 1; i <= n; i++) {
        cout << dp[i] + 1 << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}