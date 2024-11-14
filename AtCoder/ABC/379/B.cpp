#include <iostream>
#include <string>

using namespace std;

void task() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;
    for(int i = 0, cnt = 0; i < n; i++) {
        if (s[i] == 'O') ++cnt;
        else cnt = 0;
        
        if (cnt == k) {
            ++ans;
            cnt = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}