#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    ll cur = 0;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        cur = max(0ll, cur + val);
    }

    cout << cur << endl;
}

int main() {
    task();
    return 0;
}