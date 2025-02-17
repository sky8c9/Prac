#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void task() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for(string& s : grid) cin >> s;

    int a, b, c, d;
    a = b = MAX;
    c = d = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '#') {
                a = min(a, i);
                b = min(b, j);
                c = max(c, i);
                d = max(d, j);
            }
        }
    }

    for(int i = a; i <= c; i++) {
        for(int j = b; j <= d; j++) {
            if (grid[i][j] == '.') {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}