#include <iostream>

using namespace std;

void task() {
    int n, c;
    cin >> n >> c;

    int prev = -2000;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (val - prev >= c) {
            prev = val;
            ++ans;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}