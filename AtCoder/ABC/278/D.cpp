#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;

struct Node {
    ll base;
    ll delta;
};

void task() {
    int n,q;
    cin >> n;

    vector<Node> a(n + 1);
    int curBase = 0;
    for(int i = 1; i <= n; i++) {
        int val; cin >> val;

        a[i].base = curBase;
        a[i].delta = val;
    }

    cin >> q;
    while(q--) {
       int t;
       cin >> t;
       
       if (t == 1) {
            int val; cin >> val;
            curBase = val;
       } else {
            int index; cin >> index;
            if (a[index].base != curBase) {
                a[index].base = curBase;
                a[index].delta = 0;
            }    

            if (t == 2) {
                int val; cin >> val;
                a[index].delta += val;
            } else {
                cout << a[index].base + a[index].delta << endl;
            }
       }
    }
}

int main() {
    task();
    return 0;
}