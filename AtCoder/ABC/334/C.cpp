#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for(int& val : a) cin >> val;

    vector<int> suml2r(k / 2 + 1, 0);
    vector<int> sumr2l(k / 2 + 1, 0);
    for(int i = 0; i < k / 2; i++) {
        suml2r[i + 1] = a[2 * i + 1] - a[2 * i] + suml2r[i];
        sumr2l[k / 2 - 1 - i] = a[k - 1 - (2 * i)] - a[k - 1 - (2 * i + 1)] + sumr2l[k / 2 - i];
    }

    int ans = 1e9;
    for(int i = 0; i <= k / 2; i++) {
        ans = min(ans, suml2r[i] + sumr2l[i]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}