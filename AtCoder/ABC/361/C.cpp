#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int&val : a) cin >> val;

    sort(a.begin(), a.end());

    int ans = 1e9 + 1;
    int d = n - k - 1;
    for(int i = d; i < n; i++) {
        ans = min(ans, a[i] - a[i - d]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}