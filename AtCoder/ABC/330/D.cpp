#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for(string& s : grid) cin >> s;

    vector<int> sumCol(n);
    vector<int> sumRow(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (grid[i][j] == 'x') continue;
            ++sumRow[i];
            ++sumCol[j];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (grid[i][j] == 'x') continue;
            ans += ll (sumRow[i] - 1) * (sumCol[j] - 1);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}