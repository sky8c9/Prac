#include <iostream>

using namespace std;
using ll = long long;

void task() {
    ll x;
    cin >> x;

    int ans = 1;
    ll val = 1;
    while (val < x) {
        val *= ans;
        ++ans;
    }

    cout << --ans << endl;
}

int main() {
    task();
    return 0;
}