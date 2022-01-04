#include <iostream>
#include <vector>

using namespace std;

struct Dsu {
	vector<int> parents;
	vector<int> ranks;
	int n;

	Dsu(int size) {
		n = size;
		parents = vector<int>(n);
		ranks = vector<int>(n);

		for(int i = 0; i < n; i++) {
			parents[i] = i;
			ranks[i] = 1;
		}
	}

	int findP(int cur) {
		if (cur != parents[cur]){
			parents[cur] = findP(parents[cur]);
		}
		return parents[cur];
	}

	bool merge(int a, int b) {
		int pa = findP(a);
		int pb = findP(b);
		if (pa == pb) return false;
		if (ranks[pb] > ranks[pa]) parents[pa] = pb;
		else {
			if (ranks[pb] == ranks[pa]) ranks[pa]++;
			parents[pb] = pa;
		}
		return true;
	}
};

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<int> deg(n);
	Dsu uf(n);

	while(m--) { 
		int a,b;
		cin >> a >> b;
		a--;b--;

		deg[a]++;
		deg[b]++;
		bool flag = uf.merge(a,b);

		if (deg[a] >= 3 || deg[b] >= 3 || flag == false) {
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