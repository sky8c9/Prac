#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>

using ll = long long;
using namespace std;

void task() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(ll& val : a) cin >> val;
    for(ll& val : b) cin >> val;
    for(ll& val : c) cin >> val;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    priority_queue<tuple<ll, int, int, int>> pq;
    set<tuple<int, int, int>> seen;

    auto add = [&](int ai, int bi, int ci) -> void {
        if (ai == n || bi == n || ci == n) return;
        if (seen.count({ai, bi, ci})) return;

        seen.insert({ai, bi, ci});
        pq.emplace(a[ai] * b[bi] + b[bi] * c[ci] + c[ci] * a[ai], ai, bi, ci);
    };

    add(0, 0, 0);
    for(int i = 0; i < k - 1; i++) {
        auto[val, ai, bi, ci] = pq.top(); pq.pop();
        add(ai + 1, bi, ci);
        add(ai, bi + 1, ci);
        add(ai, bi, ci + 1);
    }

    auto[val, x, y, z] = pq.top();
    cout << val << endl;
}

int main() {
    task();
    return 0;
}