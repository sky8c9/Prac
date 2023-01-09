#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

void task() {
    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        for(ll p = 2; p * p * p <= n; p++) {
            ll q = n / (p * p);
            if (p * p * q == n) {
                cout << p << " " << q << endl;
                break;
            } 

            ll qq = sqrt(n / p);
            if (p * qq * qq == n) {
                cout << qq << " " << p << endl;
                break;
            }
        }
    }
}

int main() {
    task();
    return 0;
}