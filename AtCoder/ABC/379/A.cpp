#include <iostream>

using namespace std;

void task() {
    int n;
    cin >> n;

    int a = n;
    int c = a % 10;
    a /= 10;

    int b = a % 10;
    a /= 10;

    int ans1 = b * 100 + c * 10 + a;
    int ans2 = c * 100  + a * 10 + b;
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    task();
    return 0;
}