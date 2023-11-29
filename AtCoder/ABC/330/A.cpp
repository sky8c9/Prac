#include <iostream>

using namespace std;

void task() {
    int n, l;
    cin >> n >> l;

    int ans = 0;
    while(n--) {
        int val;
        cin >> val;
        ans += val >= l ? 1 : 0;
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}