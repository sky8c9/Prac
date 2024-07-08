#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    if (s[0] == 'R' || (s[1] == 'R' && s[2] == 'M')) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}