#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
const int MAX = 1e9;

map<string, map<int,int>> m;

int dfs(vector<vector<string>>& ss, int i, string t) {
    if (t.size() == 0) return 0;
    if (i >= ss.size()) return MAX;
    if (m[t][i]) return m[t][i];

    int ans = MAX;
    for(int j = 0; j < ss[i].size(); j++) {
        if (t.find(ss[i][j]) != 0) continue;
        ans = min(ans, 1 + dfs(ss, i + 1, t.substr(ss[i][j].size())));
    }

    ans = min(ans, dfs(ss, i + 1, t));
    m[t][i] = ans;
    return ans;
}

void task() {
    string t;
    cin >> t;

    int n;
    cin >> n;
    vector<vector<string>> ss(n);

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        while(a--) {
            string s;
            cin >> s;
            ss[i].push_back(s);
        }
    }

    int ans = dfs(ss, 0, t);
    if (ans != MAX) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    task();
    return 0;
}