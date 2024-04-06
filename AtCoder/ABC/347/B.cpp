#include <iostream>
#include <string>
#include <set>

using namespace std;

void task() {
    string s;
    cin >> s;

    set<string> seen;
    for(int len = 1; len <= s.size(); len++) {
        for(int i = 0; i + len <= s.size(); i++) {
            seen.insert(s.substr(i, len));
        }
    }

    cout << seen.size() << endl;
}

int main() {
    task();
    return 0;
}