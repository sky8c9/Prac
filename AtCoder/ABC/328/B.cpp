#include <iostream>
#include <string>
using namespace std;

void task() {
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int d;
        cin >> d;

        for(int j = 1; j <= d; j++) {
            string s = to_string(i) + to_string(j);

            bool flag = true;
            for(int k = 1; k < s.size(); k++) {
                if (s[k] != s[k - 1]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}