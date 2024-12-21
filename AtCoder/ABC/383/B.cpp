#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void task() {
    int h, w, d;
    cin >> h >> w >> d;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    int ans = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            for(int ii = 0; ii < h; ii++) {
                for(int jj = 0; jj < w; jj++) {
                    if (i == ii && j == jj) continue;
                    if (grid[i][j] == '.' && grid[ii][jj] == '.') {
                        int cnt = 0;
                        for(int x = 0; x < h; x++) {
                            for(int y = 0; y < w; y++) {
                                if (grid[x][y] == '#') continue;

                                bool found = false;
                                if (abs(i - x) + abs(j - y) <= d) found = true;
                                if (abs(ii - x) + abs(jj - y) <= d) found = true;
                                if (found) ++cnt;
                            }
                        }
                        ans = max(ans, cnt);
                    }
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