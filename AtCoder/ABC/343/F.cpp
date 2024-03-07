#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

struct Node {
    int first;
    int second;
    int cntF;
    int cntS;

    Node() {
        first = second = cntF = cntS = 0;
    }

    Node(int a, int b, int c, int d) {
        first = a;
        second = b;
        cntF = c;
        cntS = d;
    }
};

Node merge(Node l, Node r) { 
    unordered_map<int, int> m;
    m[l.first] += l.cntF; 
    m[l.second] += l.cntS; 
    m[r.first] += r.cntF; 
    m[r.second] += r.cntS;
    
    set<int> v{l.first, l.second, r.first, r.second};
    int first = *prev(v.end(), 1);
    int second = v.size() < 2 ? 0 : *prev(v.end(), 2);

    return Node(first, second, m[first], m[second]);
}

struct SegTree {
    vector<Node> t;
    int n;

    SegTree(int sz) {
        n = sz;
        t.resize(2 * n);

        for(int i = 0; i < 2*n; i++) {
            t[i] = Node();
        }
    }

    void update(int i, int val) {
        i += n;
        t[i].first = val;
        t[i].cntF = 1;
        for(; i > 1; i >>= 1) {     
            t[i>>1] = merge(t[i], t[i^1]);
        }
    }

    Node query(int l, int r) {
        Node ans;

        for(l+=n, r+= n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                ans = merge(ans, t[l]);
                ++l;
            }

            if (r&1) {
                --r;
                ans = merge(ans, t[r]);
            }
        }

        return ans;
    }
};

using namespace std;

void task() {
    int n, q;
    cin >> n >> q;

    SegTree segtree(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        segtree.update(i, a[i]);
    }

    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int p, x;
            cin >> p >> x;

            segtree.update(p - 1, x);
        } else {
            int l, r;
            cin >> l >> r;

            Node ans = segtree.query(l - 1, r);
            cout << ans.cntS << endl;
        }
    }
}

int main() {
    task();
    return 0;
}