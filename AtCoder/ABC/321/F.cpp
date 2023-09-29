#include <iostream>
#include <vector>

using namespace std;
int const MOD = 998244353;

void task() {
    int q, k;
    cin >> q >> k;

    vector<int> dp(k + 1);
    dp[0] = 1;
    while(q--) {
        char op;
        int val;
        cin >> op >> val;

        if (op == '+') {
            for(int i = k; i >= val; i--) {
                dp[i] += dp[i - val];
                dp[i] %= MOD;
            }
        } else if (op == '-') {
            for(int i = val; i <= k; i++) {
                dp[i] -= dp[i - val];
                dp[i] += MOD;
                dp[i] %= MOD;
            }
        }

        cout << dp[k] << endl;
    }
}

int main() {
    task();
    return 0;
}