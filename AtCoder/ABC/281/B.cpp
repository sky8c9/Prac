#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    int n = s.size();
    bool first = (s[0] - 'A') >= 0 && (s[0] - 'A' < 26);
    bool last = (s[n - 1] - 'A') >= 0 && (s[n - 1] - 'A' < 26);

    if (n != 8 || !first || !last) {
        cout << "No" << endl;
        return;
    }

    int num = 0;
    for(int i = 1; i < n - 1; i++) {
        if (s[i] - '0' < 0 || s[i] - '0' > 9) {
            cout << "No" << endl;
            return;
        }

        num = num * 10 + (s[i] - '0');
    }

    bool range = num >= 100000 && num <= 999999;
    if (range) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}