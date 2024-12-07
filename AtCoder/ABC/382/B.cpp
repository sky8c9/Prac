#include <iostream>
#include <string>

using namespace std;

void task() {
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    for(int i = n - 1; i >= 0; i--) {
        if (d == 0) break;
        if (s[i] == '@') {
            --d;
            s[i] = '.';
        }
    }

    cout << s << endl;
}

int main() {
    task();
    return 0;
}