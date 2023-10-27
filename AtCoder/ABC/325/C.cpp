#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void task() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for(string& val : grid) cin >> val;

    int ans = 0;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<int> di{-1, 0, 1, -1, 0, -1, 1, 1};
    vector<int> dj{-1, 1, 0, 0, -1, 1, -1, 1};
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (seen[i][j] || grid[i][j] == '.') continue;
            ++ans;
            queue<pair<int, int>> q;
            q.push({i, j});

            while(q.size()) {
                auto[i, j] = q.front(); q.pop();
                for(int k = 0; k < 8; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    
                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    if (seen[ni][nj] || grid[ni][nj] == '.') continue;
                    
                    seen[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}