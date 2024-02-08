#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 5 * 1e5;

struct SegTree {
    vector<int> nodes;
    int n;

    void build(int nn) {
        n = nn;
        nodes.resize(2 * n, 0);
    }

    void set(int idx, int val) {
        for (nodes[idx += n] = val; idx > 1; idx >>= 1) nodes[idx>>1] = max(nodes[idx], nodes[idx^1]);
    }

    int query(int l , int r) {
        int ans = 0;

        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, nodes[l++]);
            if (r&1) ans = max(ans, nodes[--r]);
        }

        return ans;
    }
};

void task() {
    int n, d;
    cin >> n >> d;

    int ans = 0;
    SegTree segtree;
    segtree.build(MAX);
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        int mx = segtree.query(max(1, val - d), min(MAX + 1, val + d + 1));
        ans = max(ans, mx + 1);
        segtree.set(val, mx + 1);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}