#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    for(int i = 0; i <= 2 * n; i++) {
        if (i & 1) cout << 0;
        else cout << 1;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}