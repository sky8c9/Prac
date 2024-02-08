#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int seen[61][61][61][61];
void task() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for(string& s : grid) cin >> s;

    queue<vector<int>> q;
    vector<int> pLoc(4, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (grid[i][j] == 'P') {
                if (pLoc[0] == -1) {
                    pLoc[0] = i;
                    pLoc[1] = j;
                } else {
                    pLoc[2] = i;
                    pLoc[3] = j;
                }
            }
        }
    }

    seen[pLoc[0]][pLoc[1]][pLoc[2]][pLoc[3]] = true;
    q.push(pLoc);

    int ans = 0;
    vector<int> didj{-1, 0, 1, 0, -1};
    while(q.size()) {
        int sz = q.size();

        while(sz--) {
            vector<int> cur = q.front(); q.pop();
            if (cur[0] == cur[2] && cur[1] == cur[3]) {
                cout << ans << endl;
                return;
            }

            for(int d = 0; d < 4; d++) {
                vector<int> tmp = cur;

                int ni = cur[0] + didj[d];
                int nj = cur[1] + didj[d + 1];
                if (ni >= 0 && nj >=0 && ni < n && nj < n && grid[ni][nj] != '#') {
                    tmp[0] = ni;
                    tmp[1] = nj;
                }

                ni = cur[2] + didj[d];
                nj = cur[3] + didj[d + 1];
                if (ni >= 0 && nj >=0 && ni < n && nj < n && grid[ni][nj] != '#') {
                    tmp[2] = ni;
                    tmp[3] = nj;
                }

                if (seen[tmp[0]][tmp[1]][tmp[2]][tmp[3]]) continue;
                q.push(tmp);
                seen[tmp[0]][tmp[1]][tmp[2]][tmp[3]] = true;
            }
        }

        ++ans;
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}