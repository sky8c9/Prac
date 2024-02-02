#include <iostream>
#include <string>
#include <vector>

using namespace std;
void task() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(int i = 0; i < s.size(); i++) {
        ++freq[s[i] - 'a'];
    }

    int mx = 0;
    char ans = '0';
    for(int i = 0; i < 26; i++) {
        if (freq[i] > mx) {
            mx = freq[i];
            ans = i + 'a';
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}