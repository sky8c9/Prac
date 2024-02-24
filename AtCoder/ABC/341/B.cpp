#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll&val : a) cin >> val;
    for(int i = 0; i < n - 1; i++) {
        ll s, t;
        cin >> s >> t;

        ll mul = a[i] / s;
        a[i + 1] += mul * t;
    } 

    cout << a[n - 1] << endl;
}

int main() {
    task();
    return 0;
}