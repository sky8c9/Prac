#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> h(n);
    for(int&val : h) cin >> val;

    int ans = 1;
    for(int i = 0; i < n; i++) {
        for(int d = 1; d < n; d++) {
            int cnt = 0;
            int prev = h[i];

            for(int j = i; j < n; j+=d) {
                if (h[j] == prev) ++cnt;
                else {
                    ans = max(ans, cnt);
                    cnt = 1;
                    prev = h[j];
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}