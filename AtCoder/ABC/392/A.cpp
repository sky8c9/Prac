#include <iostream>

using namespace std;

void task() {
    int a, b, c;
    cin >>  a >> b >> c;

    if (a == b * c || b == a * c || c == a * b) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}