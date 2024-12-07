#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<pair<int, int>> b(m);
    for(int&val : a) cin >> val;
    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        b.emplace_back(val, i);
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<int> ans(m, -1);
    for(int i = 0, j = 0; i < n; i++) {
        while(j < m && b[j].first >= a[i]) {
            ans[b[j++].second] = i + 1;
        }
    }

    for(int&val : ans) cout << val << endl;
}

int main() {
    task();
    return 0;
}