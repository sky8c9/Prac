#include <iostream>
#include <string>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    bool prefix = true;
    bool suffix = true;
    for(int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            prefix = false;
        }
        if (t[m - 1 - i] != s[n - 1 - i]) {
            suffix = false;
        }
    }

    if (suffix && prefix) {
        cout << 0 << endl;
    } else if (prefix) {
        cout << 1 << endl;
    } else if (suffix) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}

int main() {
    task();
    return 0;
}