#include <iostream>
#include <string>

using namespace std;

void task() {
    int n;
    string s;

    cin >> n >> s;
    for(int i = 1; i < n; i++) {
        bool flag = true;
        int cnt = 0;

        for(int j = 0; j + i < n; j++) {
            if (s[j] == s[j + i]) {
                cout << j << endl;
                flag = false;
                break;
            }
            
            ++cnt;
        }

        if(flag) cout << cnt << endl;
    }
}

int main() {
    task();
    return 0;
}