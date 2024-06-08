#include <iostream>

using namespace std;

void task() {
    int n, l, r;
    cin >> n >> l >> r;

    for(int i = 1; i <= n; i++) {
        if (i >= l && i <= r) {
            cout << r - (i - l) << " ";
        } else cout << i << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}