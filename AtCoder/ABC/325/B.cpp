#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> wx;
    for(int i = 0; i < n; i++) {
        int w, x;
        cin >> w >> x;
        wx.emplace_back(w, x);
    }

    ll ans = 0;
    for(int i = 0; i < 24; i++) {
        ll cnt = 0;

        for(auto[w, x] : wx) {
            int l = (x + i) % 24;
            int r = (l + 1) % 24; 

            if (l < r && l >= 9 && r <= 18) {
                cnt += w;
            }
        }
        
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}