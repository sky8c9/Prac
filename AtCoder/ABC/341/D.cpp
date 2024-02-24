#include <iostream>

using namespace std;
using ll = long long;

using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void task() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll lcm = (n * m) / gcd(n, m);
    ll lo = 1;
    ll hi = 1e18;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll cnt = (mid / n) + (mid / m) - 2 * (mid / lcm);

        if (cnt >= k) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
} 

int main() {
    task();
    return 0;
}