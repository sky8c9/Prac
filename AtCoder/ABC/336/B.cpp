#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    int ans = 0;
    while((n & 1) == 0) {
        ++ans;
        n >>= 1;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}