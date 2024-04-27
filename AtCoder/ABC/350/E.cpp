#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

void task() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;

    map<ll, double> dp;
    auto f = [&] (auto f, ll n) -> double {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];

        double c1 = x + f(f, n/a);
        double c2 = y;
        for(int i = 2; i <= 6; i++) {
            c2 += f(f, n/i) / 6.0;
        }

        dp[n] = min(c1, 6/5.0 * c2);
        return dp[n];
    };

    double ans = f(f, n);
    printf("%.8f\n", ans);
}

int main() {
    task();
    return 0;
}