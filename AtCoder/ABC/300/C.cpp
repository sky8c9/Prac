#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int h,w;
    cin >> h >> w;

    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    vector<int> ans(min(h, w) + 1);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '.') continue;

            int l = 0;
            while(true) {
                int d = l + 1;

                if (i - d < 0 || j - d < 0 || grid[i - d][j - d] == '.') break;
                if (i + d >= h || j + d >= w || grid[i + d][j + d] == '.') break;
                if (i - d < 0 || j + d >= w || grid[i - d][j + d] == '.') break;
                if (i + d >= h || j - d < 0 || grid[i + d][j - d] == '.') break;
                
                l = d;
            }

            ++ans[l];
        }
    }

    for(int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}