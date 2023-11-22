#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<bool> seen(n);
    queue<int> q;
    for(int i = 0; i < n - m + 1; i++) {
        bool found = true;
        for(int j = 0; j < m; j++) {
            if (t[j] != s[i + j]) {
                found = false;
                break;
            }
        }
        if (found) q.push(i);
    }

    while(q.size()) {
        int i = q.front(); q.pop();
        for(int j = i; j < i + m; j++) s[j] = '*';
        for(int j = i - m + 1; j < i + m; j++) {
            if (j < 0 || j > n - m) continue;
            if (seen[j]) continue;

            bool found = true;
            for(int k = 0; k < m; k++) {
                if (s[k + j] == '*') continue;
                if (s[k + j] != t[k]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                seen[j] = true;
                q.push(j);
            }
        }
    }

    bool checked = true;
    for(char c : s) {
        if (c != '*') {
            checked = false;
            break;
        }
    }

    if (checked) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}