#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int>> pos;
    for(int i = 1; i <= n; i++) {
        pos.push_back({i, 0});
    }

    int idx = 0;
    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            char dir;
            cin >> dir;

            auto [ni, nj] = pos[idx];
            if (dir == 'U') {
                ++nj;
            } else if (dir == 'D') {
                --nj;
            } else if (dir == 'L') {
                --ni;
            } else if (dir == 'R') {
                ++ni;
            }

            idx = (idx - 1 + n) % n;
            pos[idx].first = ni;
            pos[idx].second = nj;
        } else if (t == 2) {
            int p;
            cin >> p;
            --p;

            int idxP = (idx + p) % n;
            cout << pos[idxP].first << " " << pos[idxP].second << endl;
        }
    }
}

int main() {
    task();
    return 0;
}