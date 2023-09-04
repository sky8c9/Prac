#include <iostream>

using namespace std;

void task() {
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;
    while(m <= n) {
        ++ans;
        m += p;
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}