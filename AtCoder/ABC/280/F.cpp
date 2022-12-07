#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

struct Dsu {
    vector<int> parents;
    vector<int> ranks;

    Dsu(int n) {
        parents.resize(n);
        ranks.resize(n);
        
        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int u) {
        if (u != parents[u]) parents[u] = find(parents[u]);
        return parents[u];
    }

    bool join(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu == pv) return false;
        if (ranks[pu] > ranks[pv]) parents[pv] = pu;
        else {
            if (ranks[pu] == ranks[pv]) ranks[pv]++;
            parents[pu] = pv;
        } 

        return true;
    }
};

void task() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, ll>>> adjL(n);
    Dsu uf(n);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;

        adjL[a].emplace_back(b, c);
        adjL[b].emplace_back(a, -c);
        uf.join(a, b);
    }

    vector<bool> cycle(n);
    vector<ll> dist(n, MAX);
    for(int i = 0; i < n; i++) {
        if (uf.find(i) != i) continue;
        queue<int> qe;
        qe.push(i);
        dist[i] = 0;
        while(!qe.empty()) {
            int u = qe.front(); qe.pop();
            bool find_cycle = false;

            for(auto[v, c] : adjL[u]) {
                if (dist[v] != MAX) {
                    if (dist[v] != dist[u] + c) {
                        cycle[i] = find_cycle = true;
                        break;
                    }
                } else {
                    dist[v] = dist[u] + c;
                    qe.push(v);
                }
            }

            if (find_cycle) break;
        }
    }
        
    while(q--) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        int px = uf.find(x);
        int py = uf.find(y);
        if (px != py) cout << "nan" << endl;
        else if (cycle[px]) cout << "inf" << endl;
        else cout << dist[y] - dist[x] << endl;
    }
}

int main() {
    task();
    return 0;
}