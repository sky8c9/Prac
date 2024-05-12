#include <iostream>
#include <string>

using namespace std;

void task() {
    string s, t;
    cin >> s >> t;

    for(int i = 0, j = 0; i < t.size(); i++) {
        if (j < s.size() && t[i] == s[j]) {
            cout << i + 1 << " ";
            ++j;
        } 
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}