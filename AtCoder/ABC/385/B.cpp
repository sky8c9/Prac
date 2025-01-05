#include <iostream>
#include <string>
#include <vector>
using namespace std;

void task() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> grid(h);
    for(string& val : grid) cin >> val;

    string s;
    cin >> s;

    int ans = 0;
    int curi = x - 1;
    int curj = y - 1;
    for(int i = 0; i < s.size(); i++) {
        int ni = curi;
        int nj = curj;

        if (s[i] == 'U') {
            ni = curi - 1;
        } else if (s[i] == 'D') {
            ni = curi + 1;
        } else if (s[i] == 'L') {
            nj = curj - 1;
        } else if (s[i] == 'R') {
            nj = curj + 1;
        }

        if (curi < 0 || curi >= h || curj < 0 || curj >= w || grid[ni][nj] == '#') continue;
        if (grid[ni][nj] == '@') {
            ++ans;
            grid[ni][nj] = '.';
        }

        curi = ni;
        curj = nj;
    }

    cout << curi + 1 << " " << curj + 1 << " " << ans << endl;
}

int main() {
    task();
    return 0;
}