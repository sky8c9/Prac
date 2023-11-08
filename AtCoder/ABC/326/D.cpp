#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cntCol(vector<string>& grid) {
    int n = grid.size();
    for(int j = 0; j < n; j++) {
        vector<int> cnt(3);
        for(int i = 0; i < n; i++) {
            ++cnt[grid[i][j] - 'A'];
        }
        if (cnt[0] != 1 ||  cnt[1] != 1 || cnt[2] != 1) return false;
    }
    return true;
}

bool dfs(vector<vector<string>>& configures, vector<string>& grid, string& row, string& col, int idx, vector<bool>& seen) {
    if (idx == row.size()) {
        if (cntCol(grid)) {
            cout << "Yes" << endl;
            for(string& val : grid) cout << val << endl;
            return true;
        }
        return false;
    }

    for(string& s : configures[row[idx] - 'A']) {
        bool flag = true;
        vector<bool> nxt = seen;
        for(int j = 0; j < col.size(); j++) {
            if (!nxt[j] && s[j] != '.') {
                if (s[j] == col[j]) nxt[j] = true;
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (!flag) continue;
        grid.push_back(s);
        if (dfs(configures, grid, row, col, idx + 1, nxt)) return true;
        grid.pop_back();
    }

    return false;
}

void task() {
    int n;
    cin >> n;

    string r, c;
    cin >> r >> c;

    string s = "ABC";
    while(s.size() < n) s.push_back('.');
    sort(s.begin(), s.end());

    vector<vector<string>> configures(3);
    vector<bool> seen(n, false);
    vector<string> grid;
    do {
        for(char c : s) {
            if (c != '.') {
                configures[c - 'A'].push_back(s);
                break;
            }
        }
    } while(next_permutation(s.begin(), s.end()));

    if(!dfs(configures, grid, r, c, 0, seen)) cout << "No" << endl;
}

int main() {
    task();
    return 0;
}