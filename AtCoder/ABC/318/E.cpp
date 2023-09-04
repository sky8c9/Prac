#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    ll ans = 0;
    vector<ll> a(n);
    vector<vector<ll>> pos(n + 1); 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        if (pos[i].size() < 2) continue;
        for(int j = 1; j <= pos[i].size(); j++) {
            ans = ans + (pos[i][j] - pos[i][j - 1] - 1) * (pos[i].size() - j) * j;
        }
    }
    
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}