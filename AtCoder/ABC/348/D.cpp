#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void task() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    vector<int> didj{1,0,-1,0,1};
    for(int i = 0; i < h; i++) cin >> grid[i];

    int sX, sY, tX, tY;
    sX = sY = tX = tY = -1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') sX = i, sY = j;
            if (grid[i][j] == 'T') tX = i, tY = j;
        }
    }

    int n;
    cin >> n;

    vector<vector<int>> pos;
    bool checked = false;
    for(int i = 0; i < n; i++) {
        int r, c, e;
        cin >> r >> c >> e;
        --r; --c;
        pos.push_back({r, c, e});
    }

    pos.push_back({sX, sY, 0});
    pos.push_back({tX, tY, 0});
    int m = pos.size();
    vector<vector<int>> adjL(m);
    for(int i = 0; i < m; i++) {
        vector<vector<int>> d(h, vector<int>(w, MAX));
        auto cur = pos[i];
        d[cur[0]][cur[1]] = 0;

        queue<pair<int, int>> q;
        q.push({cur[0], cur[1]});
        while(q.size()) {
            auto [ii, jj] = q.front(); q.pop();
            for(int j = 0; j < didj.size() - 1; j++) {
                int ni = ii + didj[j];
                int nj = jj + didj[j + 1];

                if (ni < 0 || ni >= h || nj < 0 || nj >= w || d[ni][nj] != MAX || grid[ni][nj] == '#') continue;
                d[ni][nj] = d[ii][jj] + 1;
                q.push({ni, nj});
            }
        }

        for(int j = 0; j < m; j++) {
            if (i == j) continue;
            if (cur[2] >= d[pos[j][0]][pos[j][1]]) adjL[i].push_back(j);
        }
    }

    queue<int> q;
    vector<bool> seen(m, false);
    q.push(n);
    seen[n] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v : adjL[u]) {
            if (seen[v]) continue;
            seen[v] = true;
            q.push(v);

            if (v == n + 1) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
 
}

int main() {
    task();
    return 0;
}