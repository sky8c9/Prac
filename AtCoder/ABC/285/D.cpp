#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

struct DSU {
    vector<int> parents;
    vector<int> ranks;

    DSU(int n) {
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
            if (ranks[pu] == ranks[pv]) ++ranks[pv];
            parents[pu] = pv;
        }

        return true;
    }
};

void task() {
    int n;
    cin >> n;

    vector<pair<string, string>> edges;
    map<string, int> m;
    set<string> handles;
    while(n--) {
        string s,t;
        cin >> s >> t;
        
        edges.emplace_back(s, t);
        handles.insert(s);
        handles.insert(t);
    }

    int idx = 0;
    for(string handle : handles) {
        m[handle] = idx++;
    }

    DSU uf(idx);
    for(auto[u, v] : edges) {
        int uu = m[u];
        int vv = m[v];

        if (!uf.join(uu, vv)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    task();
    return 0;
}