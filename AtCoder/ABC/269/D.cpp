#include <iostream>
#include <vector>
#include <map>

using namespace std;
using P = pair<int, int>;
struct Dsu {
	vector<int> parents;
	vector<int> ranks;
	int size;
	Dsu(int n) {
		size = n;
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
		--size;
		return true;
	}
};

void task() {
	int n;
	cin >> n;

	vector<int> dx {-1,-1,0,0,1,1};
	vector<int> dy {-1,0,-1,1,0,1};
	map<P, int> m;
	Dsu uf(n);

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		m[{x,y}] = i;

		for(int j = 0; j < 6; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (m.count({nx,ny})) {
				uf.join(i, m[{nx,ny}]);
			}
		}
	}

	cout << uf.size << endl;
}

int main() {
	task();
	return 0;
}