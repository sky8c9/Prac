#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    string ending = s.substr(s.size() - 3);
    if (ending == "san") cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}