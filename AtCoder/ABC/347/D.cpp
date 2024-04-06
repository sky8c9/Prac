#include <iostream>

using namespace std;
using ll = long long;

void task() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll ansX = 0;
    ll ansY = 0;
    for(int i = 0; i < 64; i++) {
        if (c >> i & 1) {
            if (a >= b) {
                --a;
                ansX |= (1LL << i);
            } else {
                --b;
                ansY |= (1LL << i);
            }
        }
    }

    for(int i = 0; i < 64; i++) {
        if (c >> i & 1) continue;
        if (a <= 0 || b <= 0) break;
        
        --a; --b;
        ansX |= (1LL << i);
        ansY |= (1LL << i);
       
    }

    if (a == 0 && b == 0) {
        cout << ansX << " " << ansY << endl;
    } else cout << -1 << endl;
}

int main() {
    task();
    return 0;
}