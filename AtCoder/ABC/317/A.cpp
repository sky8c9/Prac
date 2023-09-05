#include <iostream>

using namespace std;

void task() {
    int n, h, x;
    cin >> n >> h >> x;

    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;

        if (p + h >= x) {
            cout << i + 1 << endl;
            break;
        }
    }
}

int main() {
    task();
    return 0;
}