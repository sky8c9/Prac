#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

void task() {
    int n,q;
    cin >> n >> q;

    map<int, unordered_set<int>> adjL;
    while(q--) {
        int t,a,b;
        cin >> t >> a >> b;

        if (t == 1) {
            adjL[a].insert(b);
        } else if (t == 2) {
            adjL[a].erase(b);
        } else {
            if (adjL[a].count(b) && adjL[b].count(a)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int main() {
    task();
    return 0;
}