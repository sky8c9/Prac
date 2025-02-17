#include <iostream>
#include <map>

using namespace std;

void task() {
    int n;
    cin >> n;

    map<int, int> p;
    map<int, int> q;
    map<int, int> rq;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        p[i] = val;
    }

    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        q[i] = val;
        rq[val] = i;
    }

    for(int i = 1; i <= n; i++) {
        cout << q[p[rq[i]]] << " ";
    }
    
    cout << endl;
}

int main() {
    task();
    return 0;
}