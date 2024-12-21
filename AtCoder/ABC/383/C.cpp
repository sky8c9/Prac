#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int MAX = 1e9;

void task() {
    int h, w, d;
    cin >> h >> w >> d;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, MAX));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == 'H') {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    vector<int> didj{1,0,-1,0,1};
    while(q.size()) {
        int sz = q.size();
        while (sz--) {
            auto[i, j] = q.front(); q.pop();
            for(int k = 0; k < 4; k++) {
                int ni = i + didj[k];
                int nj = j + didj[k + 1];

                if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] == '#') continue;
                if (dist[ni][nj] == MAX) {
                    q.push({ni, nj});
                    dist[ni][nj] = dist[i][j] + 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (dist[i][j] <= d) ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}