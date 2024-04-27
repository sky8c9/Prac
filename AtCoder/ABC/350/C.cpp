#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, int>> ans;
    for(int&val : a) cin >> val;
    for(int i = 0; i < n; i++) {
        while(a[i] - 1 != i) {
            ans.push_back({i + 1, a[i]});
            swap(a[i], a[a[i] - 1]);
        }
    }

    cout << ans.size() << endl;
    for(auto[a, b] : ans) cout << a << " " << b << endl;
}

int main() {
    task();
    return 0;
}