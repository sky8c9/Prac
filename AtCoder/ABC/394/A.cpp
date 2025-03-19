#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    for(char c : s) {
        if (c == '2') cout << 2;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}