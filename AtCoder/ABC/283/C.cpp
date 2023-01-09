#include <iostream>
#include <string>
using namespace std;
void task() {
    string s;
    cin >> s;

    int ans = 0;
    int i = 0;
    while(s[i] == '0') ++i;
    for(; i < s.size(); i++) {
        if (s[i] - '0' == 0 && i + 1 < s.size() && s[i + 1] - '0' == 0) {
            ++i;
        } 
        ++ans;
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}