#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(string& s1, string& s2) {
    int i = 0;
    for(int j = 0; j < s2.size(); j++) {
        if (s1[i] == s2[j]) ++i;
    }
    return i == s1.size();
}

void task() {
    int n;
    string t;
    cin >> n >> t;

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int diff = s.size() - t.size();
        bool flag = false;
        if (abs(diff) > 1) continue;
        if (diff == 0) {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                if (s[i] != t[i]) ++cnt;
            }
            flag = cnt <= 1;
        } else {
            flag = check(s, t) | check(t, s);
        }

        if (flag) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for(int val : ans) cout << val << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}