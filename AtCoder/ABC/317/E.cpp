#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void task() {
    int h, w;
    cin >> h >> w;

    pair<int, int> s;
    pair<int, int> g;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<string> grid(h);
    vector<int> dxdy = {1,0,-1,0,1};
    for(int i = 0; i < h; i++) {
        cin >> grid[i];
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '.') continue;
            else if (grid[i][j] == 'S') s = make_pair(i, j);
            else if (grid[i][j] == 'G') g = make_pair(i, j);
            else seen[i][j] = true;
        }
    }

    auto markedR = [&] (int i, int j, int step) {
        while(i >= 0 && i < h && grid[i][j] == '.') {
            seen[i][j] = true;
            i += step;
        }
    };

    auto markedC = [&] (int i, int j, int step) {
        while(j >= 0 && j < w && grid[i][j] == '.') {
            seen[i][j] = true;
            j += step;
        }
    };

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '^') markedR(i - 1, j, -1);
            else if (grid[i][j] == 'v') markedR(i + 1, j, 1);
            else if (grid[i][j] == '<') markedC(i, j - 1, -1);
            else if (grid[i][j] == '>') markedC(i, j + 1, 1);
        }
    }

    queue<pair<int, int>> q;    
    q.push(s);
    seen[s.first][s.second] = true;
    int len = 0;
    while(q.size()) {
        int sz = q.size();
        while(sz--) {
            auto[i, j] = q.front(); q.pop();
            for(int k = 0; k < dxdy.size() - 1; k++) {
                int ni = i + dxdy[k];
                int nj = j + dxdy[k + 1];
                
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || seen[ni][nj]) continue;
                if (ni == g.first && nj == g.second) {
                    cout << len + 1 << endl;
                    return;
                }

                seen[ni][nj] = true;
                q.push({ni, nj});
            }
        }
        ++len;
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}