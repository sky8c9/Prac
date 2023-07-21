#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int tmpTR = grid[0][n - 1];
    int tmpBR = grid[n - 1][n - 1];
    int tmpTL = grid[0][0];
    int tmpBL = grid[n - 1][0];
    for(int i = n - 1; i > 0; i--) {
        grid[0][i] = grid[0][i - 1];
        grid[i][n - 1] = grid[i - 1][n - 1];
    }

    for(int i = 0; i < n - 1; i++) {
        grid[n - 1][i] = grid[n - 1][i + 1];
        grid[i][0] = grid[i + 1][0];
    }

    grid[1][n - 1] = tmpTR;
    grid[n - 1][n - 2] = tmpBR;
    grid[n - 2][0] = tmpBL; 
    for(int i = 0; i < n; i++) cout << grid[i] << endl;
}

int main() {
    task();
    return 0;
}