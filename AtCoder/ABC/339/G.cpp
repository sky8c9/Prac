#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct Node {
    vector<int> vals;
    vector<ll> sum;

    Node(){}
    Node(vector<int>& v, vector<ll>& s) {
        vals = v;
        sum = s;
    }
};

Node merge(Node a, Node b) {
    vector<int> cvals;
    vector<ll> csum;

    merge(a.vals.begin(), a.vals.end(), b.vals.begin(), b.vals.end(), back_inserter(cvals));
    
    csum.resize(cvals.size() + 1, 0);
    for(int i = 0; i < cvals.size(); i++) {
        csum[i + 1] = csum[i] + cvals[i];
    }

    return Node(cvals, csum);
}

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int sz) {
        n = sz;
        tree.resize(2 * n);
    }

    void set(int i, int val) {
        i += n;
        tree[i].vals.push_back(val);
        tree[i].sum = vector<ll>{0, val};
    }

    void build() {
        for(int i = n - 1; i >= 1; i--) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    ll query(ll l, ll r, ll x) {
        ll ans = 0;

        for(l = l + n, r = r + n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                auto itr = upper_bound(tree[l].vals.begin(), tree[l].vals.end(), x);
                ans += tree[l].sum[itr - tree[l].vals.begin()];
                ++l;
            }

            if (r&1) {
                --r;
                auto itr = upper_bound(tree[r].vals.begin(), tree[r].vals.end(), x);
                ans += tree[r].sum[itr - tree[r].vals.begin()];
            }
        }

        return ans;
    }
};

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    SegTree segtree(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        segtree.set(i, a[i]);
    }

    segtree.build();

    int q;
    cin >> q;

    ll ans = 0;
    while(q--) {
        ll l, r, x;
        cin >> l >> r >> x;

        l ^= ans;
        r ^= ans;
        x ^= ans;

        ans = segtree.query(l - 1, r, x);
        cout << ans << endl;
    }

}

int main() {
    task();
    return 0;
}
