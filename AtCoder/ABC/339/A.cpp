#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '.') {
            cout << s.substr(i + 1) << endl;
            return;
        }
    }
}

int main() {
    task();
    return 0;
}