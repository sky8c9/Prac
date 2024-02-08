#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>> grid(h, vector<char>(w, '.'));
    vector<int> di{-1 , 0, 1, 0};
    vector<int> dj{0, 1, 0, -1};
    int i = 0;
    int j = 0;
    int r = 0;
    while(n--) {
        if (grid[i][j] == '.') {
            grid[i][j] = '#';
            ++r;
        } else {
            grid[i][j] = '.';
            --r;
        }
        
        r = (r + 4) % 4;
        i += di[r]; j += dj[r];
        i = (i + h) % h; j = (j + w) % w;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}