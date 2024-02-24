#include <iostream>
#include <vector>
#include <string>

using namespace std;
void task() {
    int h, w, n;
    cin >> h >> w >> n;

    string t;
    cin >> t;

    vector<string> grid(h);
    for(string& val : grid) cin >> val;

    int ans = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '#') continue;
            
            int ni = i;
            int nj = j;
            bool flag = true;
            for(int k = 0; k < n; k++) {
                if (t[k] == 'L') --nj;
                else if (t[k] == 'R') ++nj;
                else if (t[k] == 'U') --ni;
                else if (t[k] == 'D') ++ni;
                
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] == '#') {
                    flag = false;
                    break;
                }
            }

            if (flag) ++ans;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}