#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 3e18;

struct SegTree {
    vector<int> t;
    int sz;

    SegTree(int n) {
        sz = n;
        t.resize(2 * n, 0);
    }

    void update(int i, int val) {
        i += sz;
        t[i] = val;
        for(; i > 1; i >>= 1) {
            t[i >> 1] = t[i] + t[i ^ 1]; 
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans += t[l++];
            if (r&1) ans += t[--r];
        }
        return ans;
    }
};

void task() {
    ll q, k;
    cin >> q >> k;  

    vector<pair<ll, ll>> p;
    vector<ll> vals;  
    while(q--) {
        ll t, x;
        cin >> t >> x;

        p.emplace_back(t, x);
        vals.push_back(x);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    map<ll, int> m;
    m[-MAX] = 0;
    int idx = 1;
    for(ll& val : vals) {
        m[val] = idx++;
    }
    m[MAX] = idx;

    SegTree segtree(m.size());
    set<ll> seen;
    set<ll> openedIntervals;
    set<ll> closedIntervals;
    seen.insert(-MAX); seen.insert(MAX);
    for(auto[type, x] : p) {
        if (type == 1) {
            if (seen.count(x)) {
                auto itr = seen.find(x);
                auto itrL = prev(itr);
                auto itrR = next(itr);

                seen.erase(x);
                openedIntervals.erase(x);
                closedIntervals.erase(x);

                if (*itrR - *itrL > k) {
                    openedIntervals.insert(*itrL);
                    closedIntervals.insert(*itrR);
                }

                segtree.update(m[x], 0);
            } else {
                seen.insert(x);
                auto itr = seen.find(x);
                auto itrL = prev(itr);
                auto itrR = next(itr);

                if (x - *itrL > k) {
                    openedIntervals.insert(*itrL);
                    closedIntervals.insert(x);
                } else openedIntervals.erase(*itrL);

                if (*itrR - x > k) {
                    openedIntervals.insert(x);
                    closedIntervals.insert(*itrR);
                } else closedIntervals.erase(*itrR);

                segtree.update(m[x], 1);
            }
        } else {
            auto itrL = --openedIntervals.lower_bound(x);
            auto itrR = closedIntervals.lower_bound(x + 1);
            
            int ans = segtree.query(m[*itrL] + 1, m[*itrR]);
            cout << ans << endl;
        }
    }
}

int main() {
    task();
    return 0;
}