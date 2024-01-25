#include <iostream>
#include <string>
using namespace std;

void task() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size() - 1; i++) {
        if (s[i] > s[i + 1]) {
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