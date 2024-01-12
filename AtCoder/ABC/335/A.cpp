#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    s[s.size() - 1] = '4';
    cout << s << endl;
}

int main() {
    task();
    return 0;
}