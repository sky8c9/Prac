#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void task() {
    int q;
    cin >> q;

    queue<ll> deltas;
    ll total = 0;
    while(q--) {
        int t;
        cin >> t;

        if (t == 1) {
            deltas.push(total);
        } else if (t == 2) {
            int v;
            cin >> v;

            total += v;
        } else {
            int v;
            cin >> v;

            int ans = 0;
            while(deltas.size() && (total - deltas.front() >= v)) {
                ++ans;
                deltas.pop();
            }

            cout << ans << endl;
        } 
    }
}

int main() {
    task();
    return 0;
}