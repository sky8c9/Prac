#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct Node {
    int deg;
    int val;
    Node(int deg, int val) : deg(deg), val(val) {};
};

struct cmp {
    bool operator() (Node a, Node b) {
        ll deltaA = (ll) (a.deg + 1) * (a.deg + 1) - (ll) a.deg * a.deg;
        ll deltaB = (ll) (b.deg + 1) * (b.deg + 1) - (ll) b.deg * b.deg;
        return deltaA * a.val > deltaB * b.val;
    }
};

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    priority_queue<Node, vector<Node>, cmp> pq;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pq.push(Node(1, val));
    }

    for(int i = 0; i < n - 2; i++) {
        Node cur = pq.top(); pq.pop();
        pq.push(Node(cur.deg + 1, cur.val));
    }

    ll ans = 0;
    while(pq.size()) {
        Node cur = pq.top(); pq.pop();
        ans += (ll) cur.deg * cur.deg * cur.val;
    }
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}