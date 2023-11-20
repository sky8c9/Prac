#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    string s;
    cin >> s;

    vector<char> st;
    for(char c : s) {
        st.push_back(c);
        while(st.size() >= 3 && st.back() == 'C') {
            st.pop_back();
            char c2 = st.back();
            st.pop_back();
            char c1 = st.back();
            st.pop_back();

            if (c1 != 'A' || c2 != 'B') {
                st.push_back(c1);
                st.push_back(c2);
                st.push_back('C');
                break;
            }
        }
    }

    for(char c : st) cout << c;
    cout << endl;
}

int main() {
    task();
    return 0;
}