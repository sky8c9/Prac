#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
void task() {
    ll x,k;
    cin >> x >> k;

    ll places = 1;
    while(k--) {
        int digit = (x / places) % 10;
        places *= 10;
        x = x / places * places;
        if (digit >= 5) x += places; 
    }

    cout << x << endl;
}

int main() {
    task();
    return 0;
}