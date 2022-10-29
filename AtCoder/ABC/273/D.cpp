#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

void task() {
    int h,w,r,c;
    cin >> h >> w >> r >> c;

    int n;
    cin >> n;
    unordered_map<int, set<int>> wallR;
    unordered_map<int, set<int>> wallC;
    for(int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        wallR[r].insert(c);
        wallC[c].insert(r); 
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        char d;
        int l;
        cin >> d >> l;

        if (d == 'L') {
            auto itr = wallR[r].lower_bound(c);
            if (itr == wallR[r].begin()) c = max(1, c - l);
            else c = max(c - l, *prev(itr) + 1);
        } else if (d == 'R') {
            auto itr = wallR[r].lower_bound(c);
            if (itr == wallR[r].end()) c = min(w, c + l);
            else c = min(c + l, *itr - 1);
        } else if (d == 'U') {
            auto itr = wallC[c].lower_bound(r);
            if (itr == wallC[c].begin()) r = max(1, r - l);
            else r = max(r - l, *prev(itr) + 1);
        } else {
            auto itr = wallC[c].lower_bound(r);
            if (itr == wallC[c].end()) r = min(h, r + l);
            else r = min(r + l, *itr - 1);
        }

        cout << r << " " << c << endl;
    }
}

int main() {
    task();
    return 0;
}