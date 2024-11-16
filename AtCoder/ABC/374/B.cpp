#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void task() {
    string s, t;
    cin >> s >> t;

    int mn = min(s.size(), t.size());
    int mx = max(s.size(), t.size());
    for(int i = 0; i < mn; i++) {
        if (s[i] != t[i]) {
            cout << i + 1 << endl;
            return;
        }
    }

    if (mn == mx) cout << 0 << endl;
    else cout << mn + 1 << endl;
}

int main() {
    task();
    return 0;
}