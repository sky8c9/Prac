#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        int t, v;
        cin >> t >> v;
        p.emplace_back(t, v);
    }   

    int ans = p[0].second;
    for(int i = 1; i < n; i++) {
        int diff = p[i].first - p[i - 1].first;
        ans -= diff;
        ans = max(0, ans);
        ans += p[i].second;

    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}