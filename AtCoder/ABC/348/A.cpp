#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    cin >> n;

    string ans;

    for(int i = 1; i <= n; i++) {
        if (i % 3) ans += 'o';
        else ans += 'x';
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}