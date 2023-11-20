#include <iostream>

using namespace std;

void task() {
    int n, x;
    cin >> n >> x;

    int ans = 0;
    while(n--) {
        int s;
        cin >> s;

        if (s <= x) ans += s;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}