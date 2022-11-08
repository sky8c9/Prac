#include <iostream>
#include <string>

using namespace std;
void task() {
    string s;
    cin >> s;
    int ans = -1;

    for(int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') ans = i + 1;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}