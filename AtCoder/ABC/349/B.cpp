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

    for(int i = 1; i <= s.size(); i++) {
        int cnt = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            if (freq[c - 'a'] == i) ++cnt;
        }

        if (cnt != 0 && cnt != 2) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}