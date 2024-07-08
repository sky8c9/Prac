#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> w(n);
    for(int&val : a) cin >> val;
    for(int&val : w) cin >> val;

    vector<vector<int>> boxes(n);
    for(int i = 0; i < n; i++) {
        boxes[a[i] - 1].push_back(w[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (boxes[i].size() > 1) {
            sort(boxes[i].begin(), boxes[i].end());
            for(int j = 0; j < boxes[i].size() - 1; j++) {
                ans += boxes[i][j];
            }
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}