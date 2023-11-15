#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

struct Lazy_Seg {
    vector<int> val;
    vector<int> delta;

    Lazy_Seg(int n) {
        val.resize(n, 0);
        delta.resize(n, 0);
    }

    void prop(int id) {
        val[2 * id] += delta[id];
        val[2 * id + 1] += delta[id];

        delta[2 * id] += delta[id];
        delta[2 * id + 1] += delta[id];
        delta[id] = 0;
    }

    void updateHelper(int id, int l, int r, int u, int v, int d) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            val[id] += d;
            delta[id] += d;
            return;
        }

        int mid = l + (r - l) / 2;
        prop(id);

        updateHelper(2 * id, l, mid, u, v, d);
        updateHelper(2 * id + 1, mid + 1, r, u, v, d);

        val[id] = max(val[2 * id], val[2 * id + 1]);
    }

    void update(int n, int ql, int qr, int d) {
        return updateHelper(1, 0, n - 1, ql, qr, d);
    }

    int queryHelper(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return -MAX;
        if (u <= l && r <= v) {
            return val[id];
        }

        int mid = (l + r) / 2;
        prop(id);

        return max(queryHelper(2 * id, l, mid, u, v), queryHelper(2 * id + 1, mid + 1, r, u, v));
    }

    int query(int n, int ql , int qr) {
        return queryHelper(1, 0, n - 1, ql, qr);
    }
};

struct Node {
    int l, r, val;
    Node(int ll, int rr, int vv) {
        l = ll;
        r = rr;
        val = vv;
    }
};

void task() {
    int n, d, w;
    cin >> n >> d >> w;

    int sz = 4e5 + 1;
    vector<vector<Node>> times(sz);
    for(int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;

        times[t].emplace_back(x, x + w - 1, 1);
        times[t + d].emplace_back(x, x + w - 1, -1);
    }

    Lazy_Seg seg(4 * sz);
    int ans = 0;
    for(int i = 0; i < sz; i++) {
        for(Node node : times[i]) {
            seg.update(sz, node.l, node.r, node.val);
        }

        int cur = seg.query(sz, 0, sz);
        ans = max(ans, cur);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}