#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> helper(vector<string>& s) {
    unordered_map<string, int> m;

    for(int i = 0; i < s[0].size(); i++) {
        string str;
        for(int j = 0; j < s.size(); j++) {
            str += s[j][i];
        }
        m[str]++;
    }   

    return m;
}

void task() {
    int h,w;
    cin >> h >> w;

    vector<string> s(h);
    vector<string> t(h);
    for(string& str : s) cin >> str;
    for(string& str : t) cin >> str;

    unordered_map<string, int> m1 = helper(s);
    unordered_map<string, int> m2 = helper(t);
    for(auto[str, cnt] : m1) {
        if (m2[str] != cnt) {
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
