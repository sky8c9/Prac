#include <iostream>
#include <vector>
using namespace std;

void task() {
    vector<vector<int>> grid(9, vector(9, 0));
    vector<vector<bool>> r(9, vector<bool>(9, false));
    vector<vector<bool>> c(9, vector<bool>(9, false));
    vector<vector<bool>> g(9, vector<bool>(9, false));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> grid[i][j];
            r[i][grid[i][j] - 1] = true;
            c[j][grid[i][j] - 1] = true;
            g[i / 3 * 3 + j / 3][grid[i][j] - 1] = true;
        }
    }

    bool flag = true;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            flag &= r[i][j] & c[i][j] & g[i][j];
        }
        
        if (!(flag)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}