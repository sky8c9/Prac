#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void task() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> grid(h);
    for(string& s : grid) cin >> s;

    int ans = MAX;
    for(int r = 0; r < h; r++) {
        int op = 0;
        for(int i = 0, j = 0; j < w; j++) {
            if (grid[r][j] == 'x') {
                i = j + 1;
                op = 0;
                continue;
            }

            if (grid[r][j] == '.') ++op;
            if (j - i + 1 == k) {
                ans = min(ans, op);
                if (grid[r][i] == '.') --op;
                ++i;
            }
        }
    }

    for(int c = 0; c < w; c++) {
        int op = 0;
        for(int i = 0, j = 0; j < h; j++) {
            if (grid[j][c] == 'x') {
                i = j + 1;
                op = 0;
                continue;
            }

            if (grid[j][c] == '.') ++op;
            if (j - i + 1 == k) {
                ans = min(ans, op);
                if (grid[i][c] == '.') --op;
                ++i;
            }
        }
    }

    ans = ans == MAX ? -1 : ans;
    cout << ans << endl;

}

int main() {
    task();
    return 0;
}