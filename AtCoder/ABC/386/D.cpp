#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, char>> pos;
    for(int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        pos.emplace_back(x, y, c);
    }

    sort(pos.begin(), pos.end());
    
    int mn = 2e9;
    for(auto[x, y, c] : pos) {
        if (c == 'W') {
            mn = min(mn, y);
        } else {
            if (mn <= y) {
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