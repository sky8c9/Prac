#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n, m;
    cin >> n >> m;

    multiset<int> a;
    multiset<int> b;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a.insert(val);
    }
    
    for(int i = 0; i < m; i++) {
        int val;
        cin >> val;
        b.insert(val);
    }
    
    ll ans = 0;
    for(int val : b) {
        auto itr = a.lower_bound(val);
        if (itr == a.end()) {
            cout << -1 << endl;
            return;
        }

        a.erase(itr);
        ans += *itr;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}