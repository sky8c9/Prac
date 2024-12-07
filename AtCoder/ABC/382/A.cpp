#include <iostream>
#include <string>

using namespace std;

void task() {
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '.') ++ans;
    }

    cout << ans + d << endl;
}

int main() {
    task();
    return 0;
}