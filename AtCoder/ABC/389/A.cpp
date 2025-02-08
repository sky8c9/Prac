#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    int ans = (s[0] - '0') * (s[2] - '0');
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}