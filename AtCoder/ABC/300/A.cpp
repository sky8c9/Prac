#include <iostream>

using namespace std;

void task() {
    int n, a, b;
    cin >> n >> a >> b;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;

        if (c == (a+b)) {
            cout << i + 1 << endl;
            break;
        }
    }
}

int main() {
    task();
    return 0;
}