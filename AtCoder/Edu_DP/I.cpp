#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<double> p(n);
    for(double& val : p) cin >> val;

    vector<double> dp(n + 1);
    dp[0] = 1 - p[0]; dp[1] = p[0];
    for(int i = 1; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            dp[j + 1] = dp[j] * p[i] + dp[j + 1] * (1 - p[i]);
        }
        dp[0] *= 1 - p[i];
    }

    double ans = 0;
    for(int i = n/2 + 1; i <= n; i++) ans += dp[i];
    printf("%.10f\n", ans);
}

int main() {
    task();
    return 0;
}