#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i <= s.size() - 2; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}