#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
    int h,w;
    cin >> h >> w;

    int ans = 0;
    for(int i = 0; i < h; i++) {
        string s;
        cin >> s;

        for(char c : s) {
            ans += c == '#' ? 1 : 0;
        }
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}