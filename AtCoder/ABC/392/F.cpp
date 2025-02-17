#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1048576;

struct Lazy_Seg {
    vector<int> val;
    vector<int> delta;
    int n;

    Lazy_Seg() {
        n = MAX;
        val.resize(2 * n, 0);
        delta.resize(2 * n, 0);
    }

    void prop_(int id) {
        val[2 * id] += delta[id];
        val[2 * id + 1] += delta[id];

        delta[2 * id] += delta[id];
        delta[2 * id + 1] += delta[id];
        delta[id] = 0;
    }

    void updateH_(int id, int l, int r, int ql, int qr, int d) {
        if (l >= qr || r <= ql) return;
        if (ql <= l && r <= qr) {
            val[id] += d;
            delta[id] += d;
            return;
        }

        prop_(id);

        int mid = (l + r) / 2;
        updateH_(2 * id, l, mid, ql, qr, d);
        updateH_(2 * id + 1, mid, r, ql, qr, d);
        val[id] = val[2 * id] + val[2 * id + 1];
    }

    void update(int ql, int qr, int d) {
        return updateH_(1, 0, n, ql, qr, d);
    }

    int queryH_(int id, int l, int r, int ql, int qr) {
        if (l >= qr || r <= ql) return 0;
        if (ql <= l && r <= qr) return val[id];
        prop_(id);

        int mid = (l + r) / 2; 
        return queryH_(2 * id, l, mid, ql, qr) + queryH_(2 * id + 1, mid, r, ql, qr);
    }

    int query(int ql , int qr) {
        return queryH_(1, 0, n, ql, qr);
    }

    int find(int x) {
        return findH_(1, x);
    }

    int findH_(int id, int x) {
        if (id >= n) return id - n;
        prop_(id);

        if (x <= val[2 * id]) {
            return findH_(2 * id, x);
        } else {
            return findH_(2 * id + 1, x - val[2 * id]);
        }
    }
};

void task() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int& val : p) cin >> val;

    Lazy_Seg t;
    for(int i = 0; i < n; i++) t.update(i, i + 1, 1);

    vector<int> ans(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        int loc = t.find(p[i]);
        ans[loc] = i + 1;
        t.update(loc, loc + 1, -1);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    task();
    return 0;
}