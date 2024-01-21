#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int&val : a) cin >> val;
    
    vector<int> l(n);
    vector<int> r(n);
    l[0] = r[n - 1] = 1;
    for(int i = 1; i < n; i++) l[i] = min(l[i - 1] + 1, a[i]);
    for(int i = n - 2; i >= 0; i--) r[i] = min(r[i + 1] + 1, a[i]);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int mn = min(l[i], r[i]);
        ans = max(ans, mn);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}