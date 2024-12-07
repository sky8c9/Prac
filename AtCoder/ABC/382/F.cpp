#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

int pow_two(int x) { 
    int val = 1;
    while (val < x) val *= 2;
    return val;
}

struct Lazy_Seg {
    vector<int> val;
    vector<int> delta;
    int n;

    Lazy_Seg(int sz) {
        n = pow_two(sz);
        val.resize(2 * n, 0);
        delta.resize(2 * n, 0);
    }

    void prop_(int id, int l, int r) {
        if (delta[id] != 0) {
            val[id] = min(val[2 * id], val[2 * id + 1]);
            val[2 * id] = delta[id];
            val[2 * id + 1] = delta[id];

            delta[2 * id] = delta[id];
            delta[2 * id + 1] = delta[id];
            delta[id] = 0;
        }
    }

    void updateH_(int id, int l, int r, int ql, int qr, int d) {
        if (l >= qr || r <= ql) return;
        if (ql <= l && r <= qr) {
            val[id] = d;
            delta[id] = d;
            return;
        }

        prop_(id, l, r);
        
        int mid = (l + r) / 2;
        updateH_(2 * id, l, mid, ql, qr, d);
        updateH_(2 * id + 1, mid, r, ql, qr, d);
        val[id] = min(val[2 * id], val[2 * id + 1]);
    }

    void update(int ql, int qr, int d) {
        return updateH_(1, 0, n, ql, qr, d);
    }

    int queryH_(int id, int l, int r, int ql, int qr) {
        if (l >= qr || r <= ql) return MAX;
        if (ql <= l && r <= qr) return val[id];

        prop_(id, l, r);

        int mid = (l + r) / 2; 
        return min(queryH_(2 * id, l, mid, ql, qr), queryH_(2 * id + 1, mid, r, ql, qr));
    }

    int query(int ql , int qr) {
        return queryH_(1, 0, n, ql, qr);
    }
};

struct Node {
    int x, y, len, pos;
    Node(int x, int y, int len, int pos) : x(x), y(y), len(len), pos(pos) {}
};

bool cmp(Node a, Node b) {
    return pair<int, int>(a.x, a.y) > pair<int, int>(b.x, b.y);
}

void task() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<Node> bars;
    for(int i = 0; i < n; i++) {
        int r, c, l;
        cin >> r >> c >> l;
        --r; --c;
        bars.emplace_back(r, c, l, i);
    }

    sort(bars.begin(), bars.end(), cmp);

    Lazy_Seg segtree(w);
    segtree.update(0, segtree.n, h);
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        int mn = segtree.query(bars[i].y, bars[i].y + bars[i].len);
        ans[bars[i].pos] = mn;
        segtree.update(bars[i].y, bars[i].y + bars[i].len, mn - 1);
    }

    for(int&val : ans) cout << val << endl;
}

int main() {
    task();
    return 0;
}