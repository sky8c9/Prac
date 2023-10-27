#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MAX = 9e18;

void task() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<ll>> dist(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<vector<ll>> d(n, vector<ll>(2, MAX));
    d[0][0] = d[0][1] = 0;

    queue<vector<ll>> q;
    q.push({0, 0, 0});
    q.push({0, 1, 0});
    while(q.size()) {
        vector<ll> cur = q.front(); q.pop();
        if (cur[2] > d[cur[0]][cur[1]]) continue;

        for(int i = 0; i < n; i++) {
            if (cur[0] == i) continue;
            for(int j = cur[1]; j <= 1; j++) {
                ll cost = cur[2] + (j ? dist[cur[0]][i] * b + c : dist[cur[0]][i] * a);
                if (cost < d[i][j]) {
                    q.push({i, j, cost});
                    d[i][j] = min(d[i][j], cost);
                }
            }
        }
    }

    cout << min(d[n - 1][0], d[n - 1][1]) << endl;
}

int main() {
    task();
    return 0;
}