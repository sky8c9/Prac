#include <iostream>
#include <vector>
#include <set>

using namespace std;

void task() {
    int n, q;
    cin >> n >> q;

    vector<set<int>> nest(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        nest[i].insert(i);
        pos[i] = i;
    }

    int ans = 0;
    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int p, h;
            cin >> p >> h;
            --p; --h;

            int curPos = pos[p];
            nest[curPos].erase(p);
            nest[h].insert(p);
            pos[p] = h;

            if (nest[curPos].size() == 1) --ans;
            if (nest[h].size() == 2) ++ans;
        } else cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}