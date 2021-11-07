#include <iostream>
#include <vector>

using namespace std;
const int VAL = 2*1e5 + 1;

struct dsu {
	vector<int> parents;
	vector<int> ranks;

	dsu(int n) {
		parents = vector<int>(n);
		ranks = vector<int>(n);

		for(int i = 0; i < n; i++) {
			parents[i] = i;
			ranks[i] = 1;
		}
	}

	int findP(int cur) {
		if (cur != parents[cur]) {
			parents[cur] = findP(parents[cur]);
		}
		return parents[cur];
	}

	bool join(int a, int b) {
		int pa = findP(a);
		int pb = findP(b);

		if (pa == pb) return false;
		if (ranks[pa] > ranks[pb]) parents[pb] = pa;
		else {
			if (ranks[pa] == ranks[pb]) ranks[pb]++;
			parents[pa] = pb;
		}

		return true;
	}
};

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	dsu uf(VAL);
	for(auto& val : a) cin >> val;

	int ans = 0;
	for(int i = 0; i < n/2; i++) {
		if (a[i] == a[n-1-i]) continue;
		if (uf.join(a[i],a[n-1-i])) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}