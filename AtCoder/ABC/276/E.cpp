#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<int> didj{1,0,-1,0,1};

bool dfs(int i, int j, vector<string>& grid, vector<vector<bool>>& seen, int d, int si, int sj) {
    if (seen[i][j]) {
        if (i == si && j == sj && d >= 4) return true;
        return false;
    }

    seen[i][j] = true;
    for(int k = 0; k < didj.size() - 1; k++) {
        int ni = i + didj[k];
        int nj = j + didj[k + 1];
        if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || grid[ni][nj] == '#') continue;
        if (dfs(ni, nj, grid, seen, d+1, si, sj)) return true;
    }

    return false;
}

void task() {
    int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<bool>> seen(h, vector<bool>(w));
    
    int si = -1;
    int sj = -1;
    for(int i = 0; i < h; i++) {
        cin >> grid[i];
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }

    if (dfs(si,sj,grid,seen,0,si,sj)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    task();
    return 0;
}