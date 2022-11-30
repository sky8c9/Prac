#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

double compute(ll a, ll b, ll x) {
    return (double) a / sqrt(x + 1) + (double) b * x;
}

void task() {
    ll a,b;
    cin >> a >> b;

    ll lo = 0;
    ll hi = 1e18;
    while(hi - lo > 3) {
        ll d = (hi - lo) / 3;
        ll m1 = lo + d;
        ll m2 = hi - d;

        double f1 = compute(a,b,m1);
        double f2 = compute(a,b,m2);
        if (f1 > f2) lo = m1;
        else hi = m2;
    }

    double ans = min(min(compute(a,b,lo), compute(a,b,lo+1)), compute(a,b,lo+2));
    printf("%.10f\n", ans);
}

int main() {
    task();
    return 0;
}