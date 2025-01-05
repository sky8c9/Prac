#include <iostream>
#include <string>

using namespace std;

void task() {
    string s;
    cin >> s;

    int ans = 0;
    
    for(int i = 0, cnt = 1; i < s.size();) {
        if (s[i] != '0') {
            ++ans;
            ++i;
        } else {
            while (i < s.size() && s[i] == '0') {
                ++i;
                ++cnt;
            }
            ans += cnt / 2;
            cnt = 1;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}