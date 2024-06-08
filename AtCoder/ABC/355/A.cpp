#include <iostream>

using namespace std;

void task() {
    int a, b;
    cin >> a >> b;

    if (a != b) cout << (6 - a - b) << endl;
    else cout << -1 << endl;
}

int main() {
    task();
    return 0;
}