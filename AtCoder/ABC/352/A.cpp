#include <iostream>
#include <algorithm>

using namespace std;

void task() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int mn = min(x, y);
    int mx = max(x, y);
    if (z >= mn && z <= mx) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}