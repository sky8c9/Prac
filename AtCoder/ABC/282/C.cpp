#include <iostream>
#include <string>
using namespace std;

void task() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0, cnt = 0; i < n; i++) {
        if (s[i] == '\"') cnt = (cnt + 1) % 2;
        else if (s[i] == ',' && cnt == 0) s[i] = '.';
    }

    cout << s << endl;
}

int main() {
    task();
    return 0;
}