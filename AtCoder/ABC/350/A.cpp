#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    int num = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');
    if (num > 0 && num < 350 && num != 316) cout << "Yes" << endl;
    else cout << "No" << endl; 
}

int main() {
    task();
    return 0;
}