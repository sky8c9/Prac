#include <iostream>
#include <vector>

using namespace std;

void task() {
    int n, t;
    cin >> n >> t;

    vector<int> cntR(n, 0);
    vector<int> cntC(n, 0);
    int cntD1 = 0;
    int cntD2 = 0;
    for(int i = 0; i < t; i++) {
        int val;
        cin >> val;
        --val;

        int r = val / n;
        int c = val % n;
        
        ++cntR[r];
        ++cntC[c];

        if (r - c == 0) ++cntD1;
        if (r + c == n - 1) ++cntD2;

        if (cntR[r] == n || cntC[c] == n || cntD1 == n || cntD2 == n) {
            cout << (i + 1) << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    task();
    return 0;
}