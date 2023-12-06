#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const ll base = 331;
const ll MOD = 1000000021;

struct Node {
    ll hash;
    ll pow;

    Node() {}
    Node(ll h, ll p): hash(h), pow(p) {} 
};

Node add(Node l, Node r) {
    return Node((l.hash + r.hash * l.pow) % MOD, (l.pow * r.pow) % MOD);
}

struct SegTree {
    vector<Node> nodes;
    int n;

    void build(int nn) {
        n = nn;
        nodes.resize(2 * n, Node(0, 1));
    }

    void set(int idx, char c) {
        idx += n;
        nodes[idx].hash = c - 'a' + 1;
        nodes[idx].pow = base;

        for(int i = idx; i > 1; i >>= 1) {
            int pIdx = i >> 1;
            nodes[pIdx] = add(nodes[2 * pIdx], nodes[2 * pIdx + 1]);
        }
    }

    Node query(int l , int r) {
        Node sl(0, 1);
        Node sr(0, 1);

        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                sl = add(sl, nodes[l]);
                ++l;
            }
            if (r&1) {
                --r;
                sr = add(nodes[r], sr);
            }
        }

        return add(sl, sr);
    }
};

void task() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    SegTree segRL, segLR;
    segLR.build(s.size());
    segRL.build(s.size());

    for(int i = 0; i < n; i++) {
        segLR.set(i, s[i]);
        segRL.set(i, s[n - i - 1]);
    }
    
    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            char c;
            cin >> x >> c;

            segLR.set(x - 1, c);
            segRL.set(n - x, c);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;

            Node valLR = segLR.query(l - 1, r);
            Node valRL = segRL.query(n - r, n - l + 1);
            if (valLR.hash == valRL.hash) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }    
}

int main() {
    task();
    return 0;
}