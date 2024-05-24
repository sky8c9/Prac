#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

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
            t[i >> 1] = max(t[i], t[i ^ 1]); 
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, t[l++]);
            if (r&1) ans = max(ans, t[--r]);
        }
        return ans;
    }
};

void task() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int&val : a) cin >> val;

        set<int> seen;
        for(int val : a) seen.insert(val);

        map<int, int> m;
        int idx = 0;
        for(int val : seen) {
            m[val] = idx++;
        }

        SegTree segLR(n);
        SegTree segRL(n);
        vector<int> dpLR(n, 0);
        vector<int> dpRL(n, 0);
        int mx = 0;
        for(int i = 0; i < n; i++) {
            dpLR[i] = segLR.query(0, m[a[i]]) + 1;
            dpRL[n - i - 1] = segRL.query(m[a[n - i - 1]] + 1, n) + 1;
            mx = max(mx, dpLR[i]);

            segLR.update(m[a[i]], dpLR[i]);
            segRL.update(m[a[n - i - 1]], dpRL[n - i - 1]);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int len = dpLR[i] + dpRL[i] - 1;
            if (len == mx) ans.push_back(i + 1);
        }

        cout << ans.size() << endl;
        for(int val : ans) cout << val << " ";
        cout << endl;
    }
}

int main() {
    task();
    return 0;
}