#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    string s;
    cin >> s;

    vector<char> q;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<') q.push_back(s[i]);
        else {
            if (q.size() == 0) {
                cout << "No" << endl;
                return;
            }
            
            if ((s[i] == ')' && q.back() == '(') || (s[i] == ']' && q.back() == '[') || (s[i] == '>' && q.back() == '<')) q.pop_back();
            else {
                cout << "No" << endl;
                return;
            }
        }
    }

    if (q.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}