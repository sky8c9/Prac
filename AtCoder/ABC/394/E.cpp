#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
const int MAX = 1e9;

void task() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> d(n, vector<int>(n, MAX));
    deque<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) {
                q.push_front({i, i});
                d[i][i] = 0;
            } else if (grid[i][j] != '-') {
                q.push_back({i, j});
                d[i][j] = 1;
            }
        }
    }

    while(q.size()) {
        auto[i, j] = q.front(); q.pop_front();
        for(int ii = 0; ii < n; ii++) {
            for(int jj = 0; jj < n; jj++) {
                if (d[ii][jj] != MAX) continue;
                if (grid[ii][i] == '-' || grid[j][jj] == '-') continue;
                if (grid[ii][i] != grid[j][jj]) continue;

                d[ii][jj] = d[i][j] + 2;
                q.push_back({ii, jj});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int ans = d[i][j] == MAX ? -1 : d[i][j];
            cout << ans << " ";
        }
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}