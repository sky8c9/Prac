#include <iostream>
#include <vector>

using namespace std;

struct Dsu {
    vector<int> parents;
    vector<int> ranks;
    int size;

    Dsu(int n) {
        parents.resize(n);
        ranks.resize(n);
        size = n;

        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int cur) {
        if (cur != parents[cur]) parents[cur] = find(parents[cur]);
        return parents[cur];
    }

    bool uni(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return false;
        if (ranks[pu] > ranks[pv]) {
            parents[pv] = pu;
        } else {
            if (ranks[pu] == ranks[pv]) ++ranks[pv];
            parents[pu] = pv;
        }

        --size;
        return true;
    }
};

void task() {
    int n, m;
    cin >> n >> m;

    Dsu uf(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        uf.uni(u, v);
    }

    cout << uf.size << endl;
}

int main() {
    task();
    return 0;
}