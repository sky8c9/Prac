#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    int lcnt = 0;
    for(char c : s) {
        if (islower(c)) ++lcnt;
    }

    int ucnt = s.size() - lcnt;
    if (ucnt > lcnt) {
        for(char c : s) cout << (char) toupper(c);
        cout << endl;
    } else {
        for(char c : s) cout << (char) tolower(c);
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}