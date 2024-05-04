#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    stack<ll> st;
    while(n--) {
        ll val;
        cin >> val;

        ll cur = val;
        
        while(st.size() && st.top() == cur) {
            st.pop();
            cur += 1; 
        }

        st.push(cur);
    }

    cout << st.size() << endl;
}

int main() {
    task();
    return 0;
}