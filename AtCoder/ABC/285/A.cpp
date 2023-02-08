#include <iostream>

using namespace std;

void task() {
    int a, b;
    cin >> a >> b;

    if (2*a == b || 2*a + 1 == b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    task();
    return 0;
}