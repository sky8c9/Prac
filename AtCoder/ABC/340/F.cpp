#include <iostream>

using namespace std;
using ll = long long;

ll exgcd(ll x, ll y, ll &b, ll &a) {
    if (y == 0) {
        b = 1;
        a = 0;
        return x;
    }

    ll b1, a1;
    ll g = exgcd(y, x % y, b1, a1);

    b = -a1;
    a = -b1 - (x / y) * a1;

    return g;
}

void task() {
    ll x, y;
    cin >> x >> y;

    ll b, a;
    ll g = exgcd(x, y, b, a);

    if (2 % g) {
        cout << -1 << endl;
        return;
    } 

    b *= 2/g;
    a *= 2/g;
    cout << a << " " << b << endl;
}

int main() {
    task();
    return 0;
}