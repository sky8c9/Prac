#include <iostream>

using namespace std;
void task() {
    int n;
    cin >> n;

    int ans = 1;
    for(int i = 1; i <= n; i++) ans *= i;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}