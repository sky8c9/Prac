#include <iostream>
#include <string>
#include <set>

using namespace std;

void task() {
    string s;
    cin >> s;

    set<char> excl ({'a', 'e', 'i', 'o', 'u'});
    for(char c : s) {
        if (excl.count(c)) continue;
        cout << c;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}