#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, a;
    cin >> n >> a;

    ll prev = 0;
    while(n--) {
        ll t;
        cin >> t;

        prev = max(prev + a, t + a);
        cout << prev << endl;
    }
}

int main() {
    task();
    return 0;
}