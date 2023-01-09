#include <iostream>

using namespace std;
void task() {
    int a, b;
    cin >> a >> b;

    int ans = 1;
    while(b--) ans *= a;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}