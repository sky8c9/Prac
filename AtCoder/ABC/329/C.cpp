#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> freq(26);
    for(int i = 0, j = 0; j <= s.size(); j++) {
        if (j == s.size() || s[j] != s[i]) {
            freq[s[i] - 'a'] = max(freq[s[i] - 'a'], j - i);
            i = j;
        }
    }

    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans += freq[i];
    }

    cout << ans << endl;
} 

int main() {
    task();
    return 0;
}