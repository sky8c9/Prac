#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


void task() {
    ll n;
    cin >> n;

    while(n > 1) {
        if (n % 2) break;
        n /= 2;
    }

    while(n > 1) {
        if (n % 3) {
            cout << "No" << endl;
            return;
        }
        n /= 3;
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}