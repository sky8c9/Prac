#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    SegTree seg(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        seg.update(i, h[i]);
    }

    vector<vector<pair<int, int>>> queries(n);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l; --r;

        queries[r].emplace_back(l, i);
    }

    deque<int> st;
    vector<int> ans(q);
    for(int r = n - 1; r >= 0; r--) {
        for(auto[l, idx] : queries[r]) {
            int mx = seg.query(l + 1, r + 1);
            auto itr = lower_bound(st.begin(), st.end(), mx);
            ans[idx] = itr == st.end() ? 0 : st.size() - (itr - st.begin());
        }

        while(st.size() && h[r] > st.front()) {
            st.pop_front();
        }

        st.push_front(h[r]);
    }

    for(int& val : ans) cout << val << endl;
}

int main() {
    task();
    return 0;
}