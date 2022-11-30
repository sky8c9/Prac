#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    int ans = 0;
    for(char c : s) {
        ans += c == 'v' ? 1 : 2;
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}
