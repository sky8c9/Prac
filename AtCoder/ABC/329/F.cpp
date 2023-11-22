#include <iostream>
#include <vector>
#include <set>

using namespace std;

void task() {
    int n, q;
    cin >> n >> q;

    vector<set<int>> c(n);
    for(int i = 0; i < n; i++) {
        int color;
        cin >> color;
        c[i].insert(color);
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        if (c[a].size() < c[b].size()) {
            c[b].insert(c[a].begin(), c[a].end());
            c[a].clear();
        } else {
            c[a].insert(c[b].begin(), c[b].end());
            c[b].clear();
            swap(c[a], c[b]);
        }

        cout << c[b].size() << endl;
    }
}

int main() {
    task();
    return 0;
}