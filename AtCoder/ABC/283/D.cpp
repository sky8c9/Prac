#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>

using namespace std;
void task() {
    string s;
    cin >> s;
 
    stack<set<char>> st;
    vector<bool> seen(26);
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(set<char>());
        } else if (s[i] == ')') {
            if (!st.empty()) {
                set<char> cur = st.top(); st.pop();
                for(char c : cur) {
                    seen[c - 'a'] = false;
                }
            }
        } else {        
            if (seen[s[i] - 'a']) {
                cout << "No" << endl;
                return;
            }

            if (st.empty()) st.push(set<char>());
            st.top().insert(s[i]);
            seen[s[i] - 'a'] = true;     
        }
    }
 
    cout << "Yes" << endl;
}
 
int main() {
    task();
    return 0;
}