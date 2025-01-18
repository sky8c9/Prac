#include <iostream>

using namespace std;

void task() {
    int x;
    cin >> x;

    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9 ; j++) {
            if (i * j != x) ans += (i * j);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}