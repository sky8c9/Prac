#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    string ans;
    ans = s[0];
    ans += "UPC";

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}