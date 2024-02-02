#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void task() {
    int n;
    cin >> n;

    vector<int> q(n, 0);
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int&val : q) cin >> val;
    for(int&val : a) cin >> val;
    for(int&val : b) cin >> val;

    int mnA = 1e9;
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        mnA = min(mnA, q[i] / a[i]);
    }

    int ans = 0;
    for(int i = 0; i <= mnA; i++) {
        int mnB = 1e9;
        for(int j = 0; j < n; j++) {
            if (b[j] == 0) continue;
            int count = (q[j] - i * a[j]) / b[j];
            mnB = min(mnB, count);
        }

        mnB = max(0, mnB);
        ans = max(ans, i + mnB);
    }
    
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}