#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 1e9;

void task() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    queue<vector<int>> q;
    for(int i = 0; i < s.size(); i += 3) {
        for(int j = 0; j < 3; j++) {
            int c0 = s[i + j] == '0' ? 0 : 1;
            int c1 = 1 ^ c0;
            q.push({c0, c1});
        }
    }

    while(q.size() >= 3) {
        vector<vector<int>> c;
        for(int i = 0; i < 3; i++) {
            c.push_back(q.front());
            q.pop();
        }

        vector<int> nxt(2, MAX);
        for(int i = 0; i < 8; i++) {
            int total = 0;
            int cnt1 = 0;

            for(int j = 0; j < 3; j++) {
                total += c[j][i >> j & 1];
                cnt1 += i >> j & 1;
            }

            if (cnt1 > 1) nxt[1] = min(nxt[1], total);
            else nxt[0] = min(nxt[0], total);
        }

        q.emplace(nxt);
    }

    int ans = max(q.front()[0], q.front()[1]);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}
