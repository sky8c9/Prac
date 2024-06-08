#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parents;
    vector<int> ranks;
    int cnt;

    DSU(int n) {
        parents.resize(n);
        ranks.resize(n);
        cnt = 0;

        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int findP(int cur) {
        if (cur != parents[cur]) parents[cur] = findP(parents[cur]);
        return parents[cur];
    }

    bool join(int u, int v) {
        int pu = findP(u);
        int pv = findP(v);

        if (pu == pv) return false;
        if (ranks[pu] > ranks[pv]) {
            parents[pv] = pu;
        } else {
            if (ranks[pu] == ranks[pv]) ++ranks[pv]; 
            parents[pu] = pv;
        }

        ++cnt;
        return true;
    }
};

void task() {
    int n, q;
    cin >> n >> q;

    vector<DSU> ufs(11, DSU(n));
    vector<vector<pair<int, int>>> edges(11);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;

        for(int j = c; j <= 10; j++) {
            ufs[j].join(a, b);
        }
    }

    while(q--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        for(int i = w; i <= 10; i++) {
            ufs[i].join(u, v);
        }

        int ans = ufs[1].cnt;
        for(int i = 2; i <= 10; i++) {
            int diff = ufs[i].cnt - ufs[i - 1].cnt;
            ans += i * diff;
        }

        cout << ans << endl;
    }
}

int main() {
    task();
    return 0;
}