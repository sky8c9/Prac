#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if (s[i] == 'A' && s[j] == 'B' && s[k] == 'C') {
                    if (j - i == k - j) ++ans;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}