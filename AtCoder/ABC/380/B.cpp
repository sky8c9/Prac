#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    for(int i = 1, cnt = 0; i < s.size(); i++) {
        while (i < s.size() && s[i] == '-') {
            ++i;
            ++cnt;
        }

        cout << cnt << " ";
        cnt = 0;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}