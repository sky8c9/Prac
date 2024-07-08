#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

void task() {
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.emplace_back(x, s[i] - '0');
    }

    sort(p.begin(), p.end());
    
    vector<int> moveR;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if (p[i].second == 1) moveR.push_back(p[i].first);
        else {
            auto itr = lower_bound(moveR.begin(), moveR.end(), (ll) p[i].first - 2*t);
            ans += moveR.end() - itr;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}