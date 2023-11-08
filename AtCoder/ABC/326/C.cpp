#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& val : a) cin >> val;
    sort(a.begin(), a.end());

    int ans = 0;
    int i, j;
    i = j = 0;
    while(j < n) {
        while (i < j && a[i] + m <= a[j]) {
            ans = max(ans, j - i);
            ++i;
        }
        ++j;
    }

    ans = max(ans, j - i);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}