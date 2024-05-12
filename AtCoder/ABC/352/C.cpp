#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    ll heightS = 0;
    ll heightH = 0;
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        
        heightH = max(heightS + b, a + heightH);
        heightS += a;
    }

    cout << heightH << endl;
}

int main() {
    task();
    return 0;
}