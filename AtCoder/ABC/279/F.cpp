#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
		if (ranks[pu] > ranks[pv]) {
			parents[pv] = pu;
		} else {
			if (ranks[pu] == ranks[pv]) ++ranks[pv];
			parents[pu] = pv;
		}
		return true;
	}
};


void task() {
    int n,q;
    cin >> n >> q;

    Dsu uf(n + q + 1);
    unordered_map<int, int> ballbox;
    unordered_map<int, int> boxball;
    for(int i = 1; i <= n; i++) {
        ballbox[i] = i;
        boxball[i] = i;
    }

    while(q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            int y;
            cin >> y;

            if (boxball.count(y) == 0) continue;
            else if (boxball.count(x) == 0) {
                boxball[x] = boxball[y];
                ballbox[boxball[y]] = x;
                boxball.erase(y);
            } else {
                uf.join(boxball[x], boxball[y]);
                int pnode = uf.find(boxball[x]);

                ballbox.erase(boxball[y]);
                ballbox.erase(boxball[x]);
                boxball.erase(y);

                ballbox[pnode] = x;
                boxball[x] = pnode; 
            }
        } else if (t == 2) {
            ++n;
            if (boxball.count(x) == 0) {
                boxball[x] = n;
                ballbox[n] = x;
            } else {
                uf.join(boxball[x], n);
                int pnode = uf.find(n);

                boxball[x] = pnode;
                ballbox[pnode] = x;
            }
        } else cout << ballbox[uf.find(x)] << endl;
    }
}

int main() {
    task();
    return 0;
}