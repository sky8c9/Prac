#include <iostream>
#include <map>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int v, Node* p, Node* n) : val(v), prev(p), next(n) {};
};

struct DLL {
    Node* head;
    Node* tail;

    DLL() {
        head = new Node(-1, NULL, NULL);
        tail = new Node(-1, NULL, NULL);
        
        head->next = tail;
        tail->prev = head;
    };

    Node* push(Node* cur, int val) {
        Node* curNext = cur->next;
        Node* node = new Node(val, cur, cur->next);
        
        cur->next = node;
        curNext->prev = node;

        return node;
    }

    void remove(Node* cur) {
        Node* p = cur->prev;
        Node* n = cur->next;

        p->next = n;
        n->prev = p;
    }
};

void task() {
    int n;
    cin >> n;

    map<int, Node*> m;
    DLL l = DLL();
    Node* cur = l.head;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        cur = l.push(cur, val);
        m[val] = cur;
    }

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;

            m[y] = l.push(m[x], y);
        } else {
            int x;
            cin >> x;

            l.remove(m[x]);
            m.erase(x);
        }
    }

    cur = l.head->next;
    while(cur != l.tail) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}