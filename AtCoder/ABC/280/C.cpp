#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
    string s,t;
    cin >> s >> t;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << s.size() + 1 << endl;
}

int main() {
    task();
    return 0;
}