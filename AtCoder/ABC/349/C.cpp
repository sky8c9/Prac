#include <iostream>
#include <string>

using namespace std;

void task() {
    string s, t;
    cin >> s >> t;

    int j = 0;
    int n = t.size();
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == tolower(t[j])) ++j;
        if (j == n) break;
    }

    if ((j == t.size()) || (j == t.size() - 1 && t[j] == 'X')) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}