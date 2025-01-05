#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int k;
    string s, t;
    cin >> k >> s >> t;

    if (s.size() > t.size()) swap(s, t);
    if (t.size() - s.size() > 1) {
        cout << "No" << endl;
        return;
    }

    if (s.size() == t.size()) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) ++cnt;
            if (cnt > 1) {
                cout << "No" << endl;
                return;
            }
        }
    } else {
        int cnt = 0;
        for(int i = 0, j = 0; i < s.size() && j < t.size();) {
            if (s[i] != t[j]) {
                ++cnt;
                ++j;
            } else {
                ++i;
                ++j;
            }

            if (cnt > 1) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}