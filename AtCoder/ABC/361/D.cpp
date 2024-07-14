#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

void task() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    queue<pair<string, int>> q;
    set<string> seen;
    
    string ss = s + "..";
    string tt = t + "..";
    q.push({ss, n});
    seen.insert(ss);

    int d = 0;
    while(q.size()) {
        int sz = q.size();

        while(sz--) {
            auto [cur, pos] = q.front(); q.pop();
            if (cur == tt) {
                cout << d << endl;
                return;
            }

            for(int i = 0; i < cur.size() - 1; i+=1) {
                if (i == pos || i + 1 == pos || i == pos + 1) continue;
                swap(cur[i], cur[pos]);
                swap(cur[i + 1], cur[pos + 1]);

                if (seen.count(cur) == 0) {
                    q.push({cur, i});
                    seen.insert(cur);
                }

                swap(cur[i], cur[pos]);
                swap(cur[i + 1], cur[pos + 1]);
            }
        }

        ++d;
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}