#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int& val : p) cin >> val;

    vector<double> dp(n + 1, 0);
    for(int i = 0; i < n; i++) {
        vector<double> tmp(n + 1, 0);
        for(int j = 0; j <= i; j++) {
            tmp[j + 1] = max(dp[j + 1], 0.9 * dp[j] + p[i]);
        }
        dp = tmp;
    }

    double ans = -1e9;
    double denominator = 0;
    for(int i = 0; i < n; i++) {
        denominator += pow(0.9, i);
        double val = dp[i + 1] / denominator - 1200 / sqrt(i + 1);
        ans = max(val, ans);
    }

    printf("%.8f\n", ans);
}

int main() {
    task();
    return 0;
}