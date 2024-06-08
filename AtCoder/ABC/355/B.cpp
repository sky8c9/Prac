#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        ans.emplace_back(val, 0);
    }

    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        ans.emplace_back(val, 1);
    }

    sort(ans.begin(), ans.end());
    for(int i = 1; i < n + m; i++) {
        if (ans[i].second == ans[i - 1].second && ans[i].second == 0) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    task();
    return 0;
}