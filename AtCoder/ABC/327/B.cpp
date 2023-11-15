#include <iostream>

using namespace std;
using ll = long long;

void task() {
    ll n;
    cin >> n;

    for(int i = 1; i <= 15; i++) {
        ll val = 1;
        for(int j = 0; j < i; j++) val *= i;
        if (val == n) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}