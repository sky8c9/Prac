#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> q;
    vector<pair<ll, ll>> td;
    for(int i = 0; i < n; i++) {
        ll t, d;
        cin >> t >> d;
        td.emplace_back(t, t + d);
    }

    sort(td.begin(), td.end());
    ll t = td[0].first;
    q.push(td[0].second);

    int i = 1;
    int ans = 0;
    while(q.size() || i < n) {
        while(i < n && td[i].first == t) q.push(td[i++].second);
        while(q.size() && q.top() < t) q.pop();
        if(q.size()) {
            q.pop();
            ++ans;
            ++t;
        }
        if (q.empty() && i < n) t = td[i].first;
    }

    cout << ans << endl;

}

int main() {
    task();
    return 0;
}