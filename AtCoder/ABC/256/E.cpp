#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 1e9 + 1;

struct Dsu {
	vector<int> parents;
	vector<int> ranks;

	Dsu(int n) {
		parents.resize(n);
		ranks.resize(n);

		for(int i = 0; i < n; i++) {
			ranks[i] = 1;
			parents[i] = i;
		}
	}

	int findP(int cur) {
		if (cur != parents[cur]) {
			parents[cur] = findP(parents[cur]);
		}
		return parents[cur];
	}

	bool join(int u, int v) {
		int pu = findP(u);
		int pv = findP(v);

		if (pu == pv) return false;
		if (ranks[pu] > ranks[pv]) {
			parents[pv] = pu;
		} else {
			if (ranks[pu] == ranks[pv]) ranks[pv]++;
			parents[pu] = pv;
		}

		return true;
	}
};

void task() {
	int n;
	cin >> n;

	vector<int> x(n);
	vector<int> c(n);
	Dsu uf(n);
	ll ans = 0;

	for(int& val : x) {
		cin >> val;
		--val;
	}

	for(int& val : c) cin >> val;
	for(int i = 0; i < n; i++) {
		if (!uf.join(i, x[i])) {
			int mn = c[i];
			int cur = x[i];

			while(cur != i) {
				mn = min(mn, c[cur]);
				cur = x[cur];
			}

			ans += mn;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}