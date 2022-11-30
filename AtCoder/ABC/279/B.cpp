#include <iostream>
#include <string>

using namespace std;

void task() {
    string s,t;
    cin >> s >> t;

    int len = s.length() - t.length();
    for(int i = 0; i <= len; i++) {
        bool flag = true;

        for(int j = 0; j < t.size(); j++) {
            if (s[i+j] != t[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}
