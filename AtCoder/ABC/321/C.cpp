#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

void task() {
    int k;
    cin >> k;

    queue<ll> q;
    for(int i = 1; i < 10; i++) {
        q.push(i);
    }

    while(k) {
        ll cur = q.front(); q.pop();
        int d = cur % 10;

        for(int j = 0; j < d; j++) {
            q.push(cur * 10 + j);
        }

        --k;
        if (k == 0) {
            cout << cur << endl;
            return;
        }
    }
}

int main() {
    task();
    return 0;
}