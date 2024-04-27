#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void task() {
    string s;
    cin >> s;

    int n = s.size();
    stack<int> st;
    vector<int> match(n);

    for(int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int opn = st.top(); st.pop();
            match[opn] = i;
            match[i] = opn;
        } else if (st.size() & 1) {
            s[i] = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
        }
    }

    string ans;
    auto f = [&] (auto& f, int start, int end, int step) -> void {
        for(int i = start; i != end; i += step) {
            if (s[i] == '(') {
                f(f, match[i] - 1, i, step * -1);
                i = match[i];
            } else if (s[i] == ')') {
                f(f, match[i] + 1, i, step * -1);
                i = match[i];
            } else {
                ans += s[i];
            }
        }
    };

    f(f, 0, n, 1);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}