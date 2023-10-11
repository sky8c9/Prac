#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    for(int i = 1; i < s.size(); i += 2) {
        if (s[i] == '1') {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}