#include <iostream>
#include <string>
using namespace std;

void task() {
    string s;
    cin >> s;

    bool flag = true;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '|') flag = !flag;
        else if (flag) cout << s[i];
    }
    cout << endl;
}

int main() {
    task();
    return 0;
}