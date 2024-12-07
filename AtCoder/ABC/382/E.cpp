#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void task() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for(int&val : p) cin >> val;

    vector<double> pr(n + 2, 0);
    pr[0] = 1;
    for(int i = 0; i < n; i++) {
        vector<double> tmp(n + 2, 0);
        double val = p[i] / 100.0;

        for(int j = 0; j <= n; j++) {
            tmp[j + 1] += pr[j] * val;
            tmp[j] += pr[j] * (1 - val);
        }

        pr = tmp;
    }

    vector<double> dp(x + 1);
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i] += dp[max(i - j, 0)] * pr[j];
        }

        dp[i] = (dp[i] + 1) / (1 - pr[0]);
    }

    printf("%.8f\n", dp[x]);
    
}

int main() {
    task();
    return 0;
}