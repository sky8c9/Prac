#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> dp;
vector<vector<bool>> seen;
bool helper(vector<string>& s, int setBits, char prevC) {
    int idx = prevC - 'a';
    if (idx >= 0 && idx < 26 && seen[setBits][idx]) return dp[setBits][idx];

    bool ans = false;
    for(int i = 0; i < s.size(); i++) {
        if ((setBits >> i) & 1) continue;
        if (prevC != ' ' && prevC != s[i][0]) continue;
        ans |= !helper(s, setBits | (1 << i), s[i].back());
    }
    
    if (idx < 0 || idx >= 26) return ans;
    seen[setBits][idx] = true;
    return dp[setBits][idx] = ans;
}

void task() {
    int n;
    cin >> n;
    
    vector<string> s(n);
    dp.resize(1<<n, vector<bool>(26));
    seen.resize(1<<n, vector<bool>(26));
    for(string& val : s) cin >> val;
    bool ans = helper(s, 0, ' ');

    if (ans) cout << "First" << endl;
    else cout << "Second" << endl;
}

int main() {
    task();
    return 0;
}