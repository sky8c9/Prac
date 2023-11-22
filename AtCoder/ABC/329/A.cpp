#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    cout << s[0];
    for(int i = 1; i < s.size(); i++) {
        cout << " " << s[i];
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}