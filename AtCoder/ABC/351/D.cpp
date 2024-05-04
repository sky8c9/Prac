#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

void task() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    vector<int> didj{1, 0, -1, 0, 1};
    for(string& s : grid) cin >> s;

    vector<vector<int>> colors(h, vector<int>(w, 0));
    int ans = 1;
    int color = 0;
    for(int i = 0; i < h; i++) {   
        for(int j = 0; j < w; j++) { 
            if (grid[i][j] == '#' || colors[i][j]) continue;

            int cnt = 1;
            ++color;
            colors[i][j] = color;
            
            set<pair<int, int>> seen;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(q.size()) {
                auto[ii, jj] = q.front(); q.pop();
                
                bool isStop = false;
                for(int dir = 0; dir < didj.size() - 1; dir++) {
                    int ni = ii + didj[dir];
                    int nj = jj + didj[dir + 1];

                    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    if (grid[ni][nj] == '#') {
                        isStop = true;
                        break;
                    }
                }

                if (isStop) continue;

                for(int dir = 0; dir < didj.size() - 1; dir++) {
                    int ni = ii + didj[dir];
                    int nj = jj + didj[dir + 1];

                    if (ni < 0 || nj < 0 || ni >= h || nj >= w || colors[ni][nj] == color || grid[ni][nj] == '#') continue;
                    if (seen.count({ni, nj}) == 0) {
                        ++cnt;
                        seen.insert({ni, nj});
                    }

                    if (colors[ni][nj] == 0) {
                        colors[ni][nj] = color; 
                        q.push({ni, nj});
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}