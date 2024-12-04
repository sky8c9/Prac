#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count(int start, int blk, int end, int n) {
    bool flag = true;
    int ss = start;

    while(start != end && flag) {
        if (start == blk) flag = false;
        start = (start + 1) % n;
    }

    int diff = abs(ss - end);
    int cw = end >= ss ? diff : n - diff;
    int ccw = n - cw;

    if (flag) return cw;
    else return ccw; 
}

void task() {
    int n, q;
    cin >> n >> q;

    int posL = 0;
    int posR = 1;
    int ans = 0;
    for(int i = 0; i < q; i++) {
        char h;
        int t;
        cin >> h >> t;

        --t;
        if (h == 'R') {
            ans += count(posR, posL, t, n);
            posR = t;
        } else if (h == 'L') {
            ans += count(posL, posR, t, n);
            posL = t;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}