#include <iostream>

using namespace std;

void task() {
    int x, y;
    cin >> x >> y;

    if (y >= x && y - x <= 2) cout << "Yes" << endl;
    else if (y < x && x - y <= 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}