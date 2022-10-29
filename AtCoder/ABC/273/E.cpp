#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    Node* prev;
    Node* next;
    int val;

    Node(int val) {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void task() {
    int q;
    cin >> q;

    unordered_map<int, Node*> pointers;
    Node* cur = new Node(-1);
    while(q--) {
        string s;
        cin >> s;

        if (s == "ADD") {
            int val;
            cin >> val;
            cur->next = new Node(val);
            cur->next->prev = cur;
            cur = cur->next;
        } else if (s == "DELETE") {
            if (cur->prev != NULL) cur = cur->prev;
        } else if (s == "SAVE") {
            int index;
            cin >> index;
            pointers[index] = cur;
        } else if (s == "LOAD") {
            int index;
            cin >> index;
            cur = pointers[index] == NULL ? new Node(-1) : pointers[index];
        }

        cout << cur->val << " ";
    }

    cout << endl;
}

int main() {
    task();
    return 0;
}

