#include <iostream>
#include <string>
using namespace std;

void task() {
    int n;
    string s;
    cin >> n >> s;

    for(int i = 1; i < n; i++) {
        bool ab = s[i] == 'b' && s[i - 1] == 'a';
        bool ba = s[i] == 'a' && s[i - 1] == 'b';
        if (ab || ba) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}