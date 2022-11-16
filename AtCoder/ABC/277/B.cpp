#include <iostream>
#include <string>
#include <set>
using namespace std;

void task() {
    int n;
    cin >> n;

    set<string> seen;
    set<char> fCond;
    set<char> sCond;
    fCond.insert('H');fCond.insert('D');fCond.insert('C');fCond.insert('S');

    sCond.insert('A');sCond.insert('2');sCond.insert('3');sCond.insert('4');
    sCond.insert('5');sCond.insert('6');sCond.insert('7');sCond.insert('8');
    sCond.insert('9');sCond.insert('T');sCond.insert('J');sCond.insert('Q');
    sCond.insert('K');
    bool ans = true;
    while(n--) {
        string s;
        cin >> s;

        if (seen.count(s) || fCond.count(s[0]) == 0 || sCond.count(s[1]) == 0) ans = false;
        seen.insert(s);
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}