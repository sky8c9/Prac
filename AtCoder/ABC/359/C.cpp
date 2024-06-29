#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

void task() {
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if (sx + sy & 1) --sx;
    if (tx + ty & 1) --tx;

    ll diffY = abs(ty - sy);
    ll diffX = abs(tx - sx);
    ll ans = diffY;
    if (diffY < diffX) {
        ans = (diffX + diffY) / 2;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}