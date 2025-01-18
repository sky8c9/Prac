#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;
const int MAX = 1e9;

void task() {
    int h, w;
    cin >> h >> w;

    int si, sj, gi, gj;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) {
        cin >> grid[i];
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                si = i;
                sj = j;
            }

            if (grid[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    vector<vector<vector<int>>> d(2, vector<vector<int>>(h, vector<int>(w, MAX)));
    for(int i = 0; i < 2; i++) {
        d[i][si][sj] = 0;
        q.push({si, sj, i});
    }

    vector<int> di {-1, 1, 0, 0};
    vector<int> dj {0, 0, -1, 1};
    while(q.size()) {
        auto[i, j, k] = q.front(); q.pop();
        for(int dir = 0; dir < 2; dir++) {
            int ni = i + di[2 * k + dir];
            int nj = j + dj[2 * k + dir];

            if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] == '#') continue;
            if (d[k^1][ni][nj] <= d[k][i][j] + 1) continue;

            d[k^1][ni][nj] = d[k][i][j] + 1;
            q.push({ni, nj, k^1});
        }
    }

    int ans = min(d[0][gi][gj], d[1][gi][gj]);
    ans = ans == MAX ? -1 : ans;
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}