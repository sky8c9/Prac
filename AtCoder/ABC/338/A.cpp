#include <iostream>
#include <string>

using namespace std;
void task() {
    string s;
    cin >> s;

    if (!isupper(s[0])) {
        cout << "No" << endl;
        return;
    }

    for(int i = 1; i < s.size(); i++) {
        if (isupper(s[i])) {
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