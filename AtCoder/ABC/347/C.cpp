#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> d(n);
    for(ll&val : d) {
        cin >> val;
        val %= (a + b);
    }

    sort(d.begin(), d.end());
    if (d.back() - d.front() < a) {
        cout << "Yes" << endl;
        return;
    }

    for(int i = 1; i < n; i++) {
        if (d[i - 1] + a + b - d[i] < a) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}