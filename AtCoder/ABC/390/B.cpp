#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll& val : a) cin >> val;

    for(int i = 2; i < n; i++) {
        if (a[i - 1] * a[i - 1] != a[i] * a[i - 2]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}