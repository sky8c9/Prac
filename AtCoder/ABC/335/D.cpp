#include <iostream>
#include <string>
#include <vector>

using namespace std;
void task() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    int val = 1;
    for(int i = 0; i < n / 2; i++) {
        for(int j = i; j < n - i - 1; j++) {
            grid[i][j] = val;
            ++val;
        }

        for(int j = i; j < n - i - 1; j++) {
            grid[j][n - i - 1] = val;
            ++val;
        }

        for(int j = n - i - 1; j > i; j--) {
            grid[n - i - 1][j] = val;
            ++val;
        }

        for(int j = n - i - 1; j > i; j--) {
            grid[j][i] = val;
            ++val;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == n / 2 && j == n / 2) cout << 'T' << " ";
            else cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}
