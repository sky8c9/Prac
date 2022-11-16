#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n,m;
    cin >> n >> m;

    unordered_map<ll, ll> cost;
    ll sum = 0;
    while(n--) {
        ll val;
        cin >> val;

        sum += val;
        cost[val] += val;
    }

    if (cost.size() == m) {
        cout << 0 << endl;
        return;
    }

    ll mx = 0;
    for(auto[k,v] : cost) {
        ll prev = (k - 1 + m) % m;
        if (cost.count(prev)) continue;

        ll tt = 0;
        ll cur = k;
        while(cost.count(cur)) {
            tt += cost[cur];
            cur = (cur + 1) % m;
        }

        mx = max(mx, tt);
    }

    cout << sum - mx << endl;
}

int main() {
    task();
    return 0;
}