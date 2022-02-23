#include <iostream>
#include <vector>

using namespace std;
struct Dsu {
	vector<int> parents;
	vector<int> ranks;
	int size;

	Dsu(int n) {
		size = n;
		parents = vector<int>(n);
		ranks = vector<int>(n, 0);

		for(int i = 0; i < n; i++) {
			parents[i] = i;
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

		size--;
		return true;
	}
};

void task() {
	int n,m;
	cin >> n >> m;

	Dsu uf(n);
	for(int i = 0; i < m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		x--;y--;
		
		uf.join(x,y);
	}

	cout << uf.size << endl;
}

int main() {
	task();
	return 0;
}

